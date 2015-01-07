#include "LruCache.h"

LruCache::LruCache(int cacheSize)
{
    m_maxCacheSize = cacheSize;
    m_currCacheSize = 0;

    mapping = make_shared<unordered_map<int, shared_ptr<node>>>();
}

void LruCache::Add(int dataToCache)
{
    if (mapping->find(dataToCache) == mapping->end())
    {
        cout << dataToCache << " is NOT present. ";
        if (m_currCacheSize == m_maxCacheSize)
        {
            shared_ptr<node> last = cache;
            while (last->next)
            {
                last = last->next;
            }

            cout << "cache is full, hence deleting the least recently used (" << last->data << "). Finally Inserting" ;
            
            auto lastButOne = last->prev;
            lastButOne->next = nullptr;

            mapping->erase(mapping->find(last->data));
        }

        m_currCacheSize++;
        m_currCacheSize = m_currCacheSize < m_maxCacheSize ? m_currCacheSize : m_maxCacheSize;
        auto newNode = make_shared<node>(dataToCache);
        newNode->next = cache;
        if (cache)
        {
            cache->prev = newNode;
        }
        cache = newNode;

        mapping->insert(make_pair(dataToCache, newNode));
    }
    else
    {
        cout << dataToCache << " is already present, hence moving it to the front.";

        auto dataLocationPair = mapping->find(dataToCache);
        auto nodeToMove = dataLocationPair->second;
        auto prevNode = nodeToMove->prev;

        // Point the prev node to the next node
        prevNode->next = nodeToMove->next;

        // Point the next node (if present) to the prev node
        if (nodeToMove->next)
        {
            nodeToMove->next->prev = prevNode;
        }

        nodeToMove->prev = nullptr;
        nodeToMove->next = cache;
        cache->prev = nodeToMove;
        cache = nodeToMove;

        mapping->erase(dataLocationPair);
        mapping->insert(make_pair(dataToCache, nodeToMove));
    }

    cout << endl;
}