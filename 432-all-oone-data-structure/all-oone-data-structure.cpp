class AllOne {
public:
    map<string,int>keys;
    multiset<pair<int,string>>sorted;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(keys.count(key)){
            sorted.erase({keys[key], key});
        }
        keys[key]++;
        sorted.insert({keys[key], key});
    }
    
    void dec(string key) {
        if(keys.count(key)){
            sorted.erase({keys[key], key});
        }
        keys[key]--;
        if(keys[key])
            sorted.insert({keys[key], key});
    }
    
    string getMaxKey() {
        if(sorted.empty()) return "";
        return sorted.rbegin()->second;
    }
    
    string getMinKey() {
        if(sorted.empty()) return "";
        return sorted.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */