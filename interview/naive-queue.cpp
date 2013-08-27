// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <cmath>
#include <ctime>
#include <chrono>

template<typename T, uint64_t Q_SIZE>
class naive_queue
{
    typedef uint64_t pos_type;
    T ptrArray[Q_SIZE];
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
    naive_queue(): pushIdx(0), popIdx(0)
    {
        
    }
    
    //
    void push(T x)
    {
        std::unique_lock<std::mutex> lock(mtx);
        
        condQueueNotOverflow.wait(lock, [this]() {
            return !overflow();
        });
        
        ptrArray[(pushIdx++) % Q_SIZE] = x;
        
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
        
        T x = ptrArray[(popIdx++) % Q_SIZE];
        
        printf("pop: popIdx = %llu\n", popIdx);
        
        condQueueNotOverflow.notify_one();
        
        return x;
    }
};

// Produce
template <typename QueueType>
void produce(QueueType * queue, long & backlog, int producerId)
{
    printf("Inside produce. The active Producer: %d\n", producerId);
    
    while(backlog > 0)
    {
        int x = int(rand() % 123456789);
        
        --backlog;
        printf("Producer %d: Produced %d. Backlog left: %ld\n", producerId, x, backlog);
        
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
        int x = queue->pop();
        
        printf("Consumer %d: Consumed %d\n", consumerId, x);
    }
}

typedef naive_queue<int, 4567> queue_t;

int main (int argc, char* argv[])
{
    const size_t PRODUCERS = 17;
    const size_t CONSUMERS = 7;
    const size_t PRODUCT_NUM = (argc < 2) ? 1000 : atoi(argv[1]);
    
    ::srand((unsigned int)::time(NULL));
    
    queue_t queue;
    std::thread producers[PRODUCERS];
    std::thread consumers[CONSUMERS];
    long backlog[PRODUCERS];
    
    for(int i = 0; i < PRODUCERS; ++i)
    {
        backlog[i] = PRODUCT_NUM;
        producers[i] = std::thread(produce<queue_t>, &queue, std::ref(backlog[i]), i);
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

