#include<list>
int max_size;
list<pair<int,int>> lru;
unordered_map<int,list<pair<int,int>>::iterator> ump;
LRUCache::LRUCache(int capacity) {
    lru.clear();
    ump.clear();
     max_size = capacity;
}

int LRUCache::get(int key) {
        if(ump.find(key) == ump.end())
            return -1;
        int value = (*ump[key]).second;      
        lru.erase(ump[key]);
        lru.push_front(make_pair(key,value));
        ump[key] = lru.begin();
        return value;
    }

void LRUCache::set(int key, int value) {
    if(ump.find(key) == ump.end())
        {
            if(lru.size() == max_size)
            {
                ump.erase(lru.back().first);
                lru.pop_back();
                lru.push_front(make_pair(key,value));
                ump[key] = lru.begin();
            }
            else
            {
                lru.push_front(make_pair(key,value));
                ump[key] = lru.begin();
            }
        }
        else
        {
            lru.erase(ump[key]);
            lru.push_front(make_pair(key,value));
            ump[key] = lru.begin();
        }
}
