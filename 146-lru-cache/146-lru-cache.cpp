class LRUCache {
public:
    list<int> items;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int capacity{0};
    int size{0};
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto pos = cache.find(key);
        
        if(pos == cache.end())
            return -1;
            
        items.erase(pos->second.second);
        items.push_front(key);
        cache[key] = {pos->second.first, items.begin()};
        return pos->second.first;
    }
    
    void put(int key, int value) {
        auto pos = cache.find(key);
        if(pos == cache.end())
        {
            items.push_front(key);
            cache[key] = {value, items.begin()};
            
            // if lru is full, remove last element
            if(size >= capacity)
            {
                cache.erase(items.back());
                items.pop_back();
            }

            size++;
        }
        else
        {
            items.erase(pos->second.second);
            items.push_front(key);
            cache[key] = {value, items.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */