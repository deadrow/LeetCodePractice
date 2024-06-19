class LRUCache {
public:
    list<int>keys;
    unordered_map<int,list<int>::iterator>keyToIter;
    unordered_map<int,int>keyToValue;
    int capacity;
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it = keyToValue.find(key);
        if(it == keyToValue.end()) return -1;

        // if present
        // get the iterator and move it to front
        auto curIter = keyToIter[key];
        keys.erase(curIter);
        keys.push_front(key);
        keyToIter[key] = keys.begin();
        return keyToValue[key];
    }
    
    void put(int key, int value) {
        // check is already present
        // if present, put it in front
        auto it = keyToValue.find(key);
        if(it != keyToValue.end()) {
            // get the iterator
            auto curIter = keyToIter[key];
            keys.erase(curIter);
            keys.push_front(key);
            keyToIter[key] = keys.begin();
            keyToValue[key] = value;
        } else {
            // check if full capacity
            if(capacity == keys.size()) {
                // remove last
                int lastKey = keys.back();
                keyToIter.erase(lastKey);
                keyToValue.erase(lastKey);
                keys.pop_back();
            }

            keys.push_front(key);
            auto newIter = keys.begin();
            keyToIter[key] = newIter;
            keyToValue[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */