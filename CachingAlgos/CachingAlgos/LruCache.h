#include "Headers.h"

class node
{
public:
    node(int data)
    {
        this->data = data;
        prev = next = nullptr;
    }

    int data;
    shared_ptr<node> prev;
    shared_ptr<node> next;
};

class LruCache
{
public:
    LruCache(int cacheSize);

    shared_ptr<node> cache;
    shared_ptr<unordered_map<int, shared_ptr<node>>> mapping;

    void Add(int dataToCache);

private:
    int m_maxCacheSize;
    int m_currCacheSize;
};