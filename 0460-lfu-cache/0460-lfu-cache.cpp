class LFUCache {
public:
    int capacity{0};
    int curSize{0};
    map<int, list<int>> countMapToList;
    map<int,int> keyToValueMap;
    map<int, pair<int, list<int>::iterator> > keyToCountItrAddress;
    LFUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        auto it = keyToCountItrAddress.find(key);
        if(it ==  keyToCountItrAddress.end())
            return -1;
        
        int curCount = keyToCountItrAddress[key].first;
        auto countMapItr = keyToCountItrAddress[key].second;
        
        int newCount = curCount+1;
        countMapToList[curCount].erase(countMapItr);
        
        if(countMapToList[curCount].empty())
            countMapToList.erase(curCount);
        
        countMapToList[newCount].push_front(key);
                
        keyToCountItrAddress[key] = {newCount, countMapToList[newCount].begin()};
        
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
            
            keyToValueMap[key] = value;
            
            keyToCountItrAddress[key] = {newCount, countMapToList[newCount].begin()};
            

            curSize++;
        }
        else
        {
            int curCount = keyToCountItrAddress[key].first;
            auto countMapItr = keyToCountItrAddress[key].second;
            
            int newCount = curCount+1;
            countMapToList[curCount].erase(countMapItr);
            
            if(countMapToList[curCount].empty())
                countMapToList.erase(curCount);
            
            countMapToList[newCount].push_front(key);
            
            keyToValueMap[key] = value;
            
            keyToCountItrAddress[key] = {newCount, countMapToList[newCount].begin()};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */