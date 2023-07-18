class LRUCache {
public:
    unordered_map<int,pair<list<int>::iterator,int>>dict;
    list<int>vals;
    int capacity;
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if(!dict.count(key))
            return -1;
        
        auto itr = dict[key].first;
        int val = dict[key].second;
        vals.erase(itr);
        vals.push_front(key);
        dict[key] = {vals.begin(), val};
        return val;
    }
    
    void put(int key, int value) {
        // if key is present
        if(dict.count(key))
        {
            auto itr = dict[key].first;
            vals.erase(itr);
            vals.push_front(key);
            dict[key] = {vals.begin(), value};
        }
        else // if key not present
        {
            if(capacity == vals.size()) // already full, evict
            {
                auto val = vals.back();
                vals.pop_back();
                dict.erase(val);
            }

            vals.push_front(key);
            dict[key] = {vals.begin(), value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */