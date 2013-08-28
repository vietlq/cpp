// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <cmath>
#include <ctime>
#include <chrono>

template<typename T>
class lock_circular_buffer
{
    typedef uint64_t pos_type;
    uint32_t queueSize;
    T * ptrArray;
    // Head
    pos_type pushIdx;
    // Tail
    pos_type popIdx;
    std::condition_variable condQueueHasData;
    std::condition_variable condQueueNotOverflow;
    std::mutex mtx;
    
    bool overflow() const
    {
        return (popIdx + queueSize <= pushIdx);
    }
    
    bool empty() const
    {
        return (popIdx >= pushIdx);
    }
public:
    //
    explicit lock_circular_buffer(uint32_t queueSize_ = 1024):
    queueSize(queueSize_), ptrArray(NULL),
    pushIdx(0), popIdx(0)
    {
        if(queueSize_ < 64) queueSize = 64;
        ptrArray = new T[queueSize];
    }
    
    ~lock_circular_buffer()
    {
        if(NULL != ptrArray)
        {
            delete[] ptrArray;
            ptrArray = NULL;
        }
    }
    
    //
    void push(T x)
    {
        std::unique_lock<std::mutex> lock(mtx);
        
        condQueueNotOverflow.wait(lock, [this]() {
            return !overflow();
        });
        
        ptrArray[pushIdx++ % queueSize] = x;
        
        printf("push: pushIdx = %llu\n", pushIdx);
        
        condQueueHasData.notify_one();
    }
    
    //
    T pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        
        condQueueHasData.wait(lock, [this]() {
            return !empty();
        });
        
        T x = ptrArray[popIdx++ % queueSize];
        
        printf("pop: popIdx = %llu\n", popIdx);
        
        condQueueNotOverflow.notify_one();
        
        return x;
    }
};

// Produce
template <typename QueueType>
void produce(QueueType & queue, long & backlog, int producerId)
{
    printf("Inside produce. The active Producer: %d\n", producerId);
    
    while(backlog > 0)
    {
        int x = int(rand() % 123456789);
        
        --backlog;
        printf("Producer %d: Produced %d. Backlog left: %ld\n", producerId, x, backlog);
        
        queue.push(x);
    }
}

// Consume
template <typename QueueType>
void consume(QueueType & queue, int consumerId)
{
    printf("Inside consume. The active Consumer: %d\n", consumerId);
    
    while(1)
    {
        int x = queue.pop();
        
        printf("Consumer %d: Consumed %d\n", consumerId, x);
    }
}

int main (int argc, char* argv[])
{
    typedef lock_circular_buffer<int> queue_t;
    const size_t PRODUCERS = 17;
    const size_t CONSUMERS = 7;
    const size_t PRODUCT_NUM = (argc < 2) ? 1000 : atoi(argv[1]);
    
    ::srand((unsigned int)::time(NULL));
    
    queue_t queue(4567);
    std::thread producers[PRODUCERS];
    std::thread consumers[CONSUMERS];
    long backlog[PRODUCERS];
    
    for(int i = 0; i < PRODUCERS; ++i)
    {
        backlog[i] = PRODUCT_NUM;
        producers[i] = std::thread(produce<queue_t>, std::ref(queue), std::ref(backlog[i]), i);
    }
    
    for(int i = 0; i < CONSUMERS; ++i)
    {
        consumers[i] = std::thread(consume<queue_t>, std::ref(queue), i);
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

