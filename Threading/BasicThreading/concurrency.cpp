#include "Headers.h"

struct Counter
{
    int value;

    Counter()
        :value(0)
    {
    }

    void increment()
    {
        value++;
    }

    void decrement()
    {
        if (value == 0)
            throw "value cannot be less than 0.";

        --value;
    }
};

struct ConcurrentCounter {
    mutex mutex;
    Counter counter;

    void increment(){
        mutex.lock();
        counter.increment();
        mutex.unlock();
    }

    void decrement(){
        mutex.lock();
        counter.decrement();
        mutex.unlock();
    }
};

struct ConcurrentSafeCounter
{
    mutex m;
    Counter counter;

    void increment()
    {
        lock_guard<mutex> guard(m);
        counter.increment();
    }

    void decrement()
    {
        lock_guard<mutex> guard(m);
        counter.decrement();
    }

};

void IncrementCounterNoMutex()
{
    cout << "Increment counter without mutex" << endl;
    for (int c = 0; c < 5; c++)
    {
        Counter counter;
        vector<thread> threads;
        for (int i = 0; i < 5; i++)
        {
            threads.push_back(thread(
                [&counter]()
            {
                this_thread::sleep_for(chrono::milliseconds(5));
                for (int j = 0; j < 100; j++)
                    counter.increment();
            }));
        }
        for (auto& t : threads)
        {
            t.join();
        }

        cout << "Counter: " << counter.value << endl;
    }
}

void IncrementCounterConcurrentlyUnsafe()
{
    cout << endl << "Increment counter with mutex but unsafe (without unlocking mutex)" << endl;

    for (int c = 0; c < 5; c++)
    {
        ConcurrentCounter counter;
        counter.counter.value = 5000;
        vector<thread> threads;
        for (int i = 0; i < 5; i++)
        {
            threads.push_back(thread(
                [&counter]()
            {
                this_thread::sleep_for(chrono::milliseconds(15));
                for (int j = 0; j < 1000; j++)
                    counter.decrement();
            }));
        }
        for (auto& t : threads)
        {
            t.join();
        }

        cout << "Counter: " << counter.counter.value << endl;
    }
}

void IncrementCounterConcurrentlySafe()
{
    cout << endl << "Increment counter concurrently and be safe (using lock_guard)" << endl;

    for (int c = 0; c < 5; c++)
    {
        ConcurrentSafeCounter counter;
        counter.counter.value = 5000;
        vector<thread> threads;
        for (int i = 0; i < 5; i++)
        {
            threads.push_back(thread(
                [&counter]()
            {
                this_thread::sleep_for(chrono::milliseconds(5));
                for (int j = 0; j < 1000; j++)
                    counter.decrement();
            }));
        }
        for (auto& t : threads)
        {
            t.join();
        }

        cout << "Counter: " << counter.counter.value << endl;
    }
}