// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <cmath>
#include <ctime>
#include <chrono>

template<typename T, uint64_t Q_SIZE>
class NaiveQueue
{
    typedef uint64_t pos_type;
    T * ptrArray[Q_SIZE];
    // Head
    pos_type pushIdx;
    // Tail
    pos_type popIdx;
    static const pos_type Q_MASK = Q_SIZE - 1;
    std::condition_variable condQueueHasData;
    std::condition_variable condQueueNotOverflow;
    std::mutex mtx;
    
    bool overflow() const
    {
        return (popIdx + Q_SIZE <= pushIdx);
    }
    
    bool empty() const
    {
        return (popIdx >= pushIdx);
    }
public:
    //
    NaiveQueue(): pushIdx(0), popIdx(0)
    {
        
    }
    
    //
    inline void push(T & obj)
    {
        push(&obj);
    }
    
    //
    void push(T * x)
    {
        std::unique_lock<std::mutex> lock(mtx);
        
        condQueueNotOverflow.wait(lock, [this]() {
            return !overflow();
        });
        
        ptrArray[pushIdx++ & Q_MASK] = x;
        
        printf("push: pushIdx = %llu\n", pushIdx);
        
        condQueueHasData.notify_one();
    }
    
    //
    T * pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        
        if(condQueueHasData.wait_for(lock, std::chrono::milliseconds(3000), [this]() {
            return !empty();
        }))
        {
            T * x = ptrArray[popIdx++ & Q_MASK];
            
            printf("pop: popIdx = %llu\n", popIdx);
            
            condQueueNotOverflow.notify_one();
            
            return x;   
        }
        else
        {
            return NULL;
        }
    }
};

// Produce
template <typename QueueType>
void produce(QueueType * queue, long * backlog, int producerId)
{
    printf("Inside produce. The active Producer: %d\n", producerId);
    
    while(*backlog > 0)
    {
        int * x = new int(rand() % 123456789);
        
        --(*backlog);
        printf("Producer %d: Produced %d. Backlog left: %ld\n", producerId, *x, *backlog);
        
        queue->push(x);   
    }
}

// Consume
template <typename QueueType>
void consume(QueueType * queue, int consumerId)
{
    printf("Inside consume. The active Consumer: %d\n", consumerId);
    
    while(1)
    {
        int * x = queue->pop();
        
        if(NULL != x)
        {
            printf("Consumer %d: Consumed %d\n", consumerId, *x);
            
            delete x;
        }
        else
        {
            printf("Timeout! Exiting the Consumer: %d\n", consumerId);
            break;
        }
    }
}

typedef NaiveQueue<int, (1 << 12)> queue_t;

int main (int argc, char* argv[])
{
    const size_t PRODUCERS = 16;
    const size_t CONSUMERS = 16;
    const size_t PRODUCT_NUM = (argc < 2) ? 1000 : atoi(argv[1]);
    
    ::srand((unsigned int)::time(NULL));
    
    queue_t queue;
    std::thread producers[PRODUCERS];
    std::thread consumers[CONSUMERS];
    long backlog[PRODUCERS];
    
    for(int i = 0; i < PRODUCERS; ++i)
    {
        backlog[i] = PRODUCT_NUM;
        producers[i] = std::thread(produce<queue_t>, &queue, &backlog[i], i);
    }
    
    for(int i = 0; i < CONSUMERS; ++i)
    {
        consumers[i] = std::thread(consume<queue_t>, &queue, i);
    }
    
    for(auto & t: consumers)
    {
        t.join();
    }
    
    for(auto & t: producers)
    {
        t.join();
    }
    
    return 0;
}

