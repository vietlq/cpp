// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <cmath>
#include <ctime>

template<typename T, size_t Q_SIZE>
class NaiveQueue
{
    T * ptrArray[Q_SIZE];
    // Head
    size_t pushIdx;
    // Tail
    size_t popIdx;
    static const size_t Q_MASK = Q_SIZE - 1;
    std::condition_variable condQueueEmpty;
    std::condition_variable condQueueOverflow;
    std::mutex mtx;
    
    bool notOverflow() const
    {
        return (popIdx + Q_SIZE > pushIdx);
    }
    
    bool notEmpty() const
    {
        return (popIdx < pushIdx);
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
        
        condQueueOverflow.wait(lock, [this]() {
            return notOverflow();
        });
        
        ptrArray[pushIdx++ & Q_MASK] = x;
        
        printf("push: pushIdx = %lu\n", pushIdx);
        
        condQueueEmpty.notify_one();
    }
    
    //
    T * pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        
        condQueueEmpty.wait(lock, [this]() {
            return notEmpty();
        });
        
        T * x = ptrArray[popIdx++ & Q_MASK];
        
        printf("pop: popIdx = %lu\n", popIdx);
        
        condQueueOverflow.notify_one();
        
        return x;
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
    }
}

typedef NaiveQueue<int, (1 << 12)> queue_t;

int main ()
{
    const size_t PRODUCERS = 16;
    const size_t CONSUMERS = 16;
    const size_t PRODUCT_NUM = 10000;
    
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

