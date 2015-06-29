#include "Headers.h"

void StartingSingleThread();
void StartingMultipleThread();
void StartingMultipleThreadsViaLambda();

void hello()
{
    cout << "Hello from thread " << this_thread::get_id() << "." << endl;
}

int main()
{
    /*StartingSingleThread();
    StartingMultipleThread();
    StartingMultipleThreadsViaLambda();

    IncrementCounterNoMutex();
    IncrementCounterConcurrentlyUnsafe();
    IncrementCounterConcurrentlySafe();*/

    MultipleProducerConsumer();

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void StartingSingleThread()
{
    cout << "Starting a single thread..." << endl;
    // Single thread
    thread t1(hello);
    t1.join();
}

void StartingMultipleThread()
{
    cout << endl << "Starting multiple threads..." << endl;
    // Multiple threads
    vector<thread> threads;
    for (int i = 0; i < 3; i++)
    {
        threads.push_back(thread(hello));
    }

    for (auto& t : threads)
    {
        t.join();
    }
}

void StartingMultipleThreadsViaLambda()
{
    cout << endl << "Starting multiple threads(lambda)..." << endl;
    // Threads via lambda
    vector<thread> threads;
    for (int i = 0; i < 3; i++)
    {
        threads.push_back(thread(
            []()
        {
            cout << "Hello from thread (lambda) " << this_thread::get_id() << "." << endl;
        }));
    }

    for (auto& t : threads)
    {
        t.join();
    }
}
