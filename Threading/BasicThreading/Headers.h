#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <vector>

using namespace std;

// Starting threads
void StartingSingleThread();
void StartingMultipleThread();
void StartingMultipleThreadsViaLambda();

// Handling Concurrency
void IncrementCounterNoMutex();
void IncrementCounterConcurrentlyUnsafe();
void IncrementCounterConcurrentlySafe();

struct BoundedBuffer;

// Condition Variables
void consumer(int id, BoundedBuffer& buffer);
void producer(int id, BoundedBuffer& buffer);
void MultipleProducerConsumer();