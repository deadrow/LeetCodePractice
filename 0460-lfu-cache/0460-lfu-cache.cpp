class LFUCache {
public:
    int capacity{0};
    int curSize{0};
    map<int, list<int>> countMapToList; // map to hold frequency vs list of items
    unordered_map<int,int> keyToValueMap; // key to value map
    unordered_map<int, pair<int, list<int>::iterator> > keyToCountItrAddress; // key to pair of latest frequency and address of item in countMapToList
    
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = keyToCountItrAddress.find(key);
        if(it ==  keyToCountItrAddress.end())
            return -1;
        
        incrementCount(key);
        
        return keyToValueMap[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        
        auto it = keyToCountItrAddress.find(key);
        if(it == keyToCountItrAddress.end())
        {
            if(curSize >= capacity)
            {
                // remove the least used
                // We use countMapToList which stores
                // frequency in sorted order
                auto firstElem = countMapToList.begin();
                int key = firstElem->second.back();
                firstElem->second.pop_back();
                
                if(firstElem->second.empty())
                    countMapToList.erase(firstElem);
                
                keyToCountItrAddress.erase(key);
                keyToValueMap.erase(key);
            }
            
            int newCount = 1;
            countMapToList[newCount].push_front(key);
            
            keyToCountItrAddress[key] = {newCount, countMapToList[newCount].begin()};
            
            curSize++;
        }
        else
        {
            incrementCount(key);
        }
        
        keyToValueMap[key] = value;
    }
    
    void incrementCount(int key){
        // increment count if the element is already present
        // 1. First remove the element from current freqeuncy count
        // 2. Add it to current freqeuncy+1 count
        int curCount = keyToCountItrAddress[key].first;
        auto countMapItr = keyToCountItrAddress[key].second;
        
        int newCount = curCount+1;
        countMapToList[curCount].erase(countMapItr);
        
        if(countMapToList[curCount].empty())
            countMapToList.erase(curCount);
        
        countMapToList[newCount].push_front(key);
        
        keyToCountItrAddress[key] = {newCount, countMapToList[newCount].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */