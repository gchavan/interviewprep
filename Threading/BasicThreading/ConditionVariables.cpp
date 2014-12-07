#include "Headers.h"

struct BoundedBuffer
{
    int* buffer;
    int capacity;
    int rear;
    int front;
    int count;

    mutex lock;
    condition_variable not_full;
    condition_variable not_empty;

    BoundedBuffer(int capacity)
        : capacity(capacity),
        rear(0),
        front(0),
        count(0)
    {
        buffer = new int[capacity];
    }

    ~BoundedBuffer()
    {
        delete[] buffer;
    }

    void deposit(int data)
    {
        unique_lock<mutex> l(lock);

        not_full.wait(l, [this](){ return count != capacity; });

        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        ++count;

        not_empty.notify_one();
    }

    int fetch()
    {
        unique_lock<mutex> l(lock);

        not_empty.wait(l, [this](){ return count != 0; });

        int result = buffer[front];
        front = (front + 1) % capacity;
        --count;

        not_full.notify_one();

        return result;
    }
};

void consumer(int id, BoundedBuffer& buffer)
{
    for (int i = 0; i < 5; i++)
    {
        int value = buffer.fetch();
        cout << "Consumer " << id << " fetched " << value << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

void producer(int id, BoundedBuffer& buffer)
{
    for (int i = 0; i < 5; i++)
    {
        buffer.deposit(i);
        cout << "Producer " << id << " deposited " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void MultipleProducerConsumer()
{
    BoundedBuffer buffer(15);
    thread c1(consumer, 1, ref(buffer));
    thread c2(consumer, 2, ref(buffer));
    thread c3(consumer, 3, ref(buffer));
    thread p1(producer, 1, ref(buffer));
    thread p2(producer, 2, ref(buffer));
    thread p3(producer, 3, ref(buffer));

    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();
    p3.join();
}