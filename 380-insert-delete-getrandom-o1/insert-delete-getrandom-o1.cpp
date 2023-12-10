class RandomizedSet {
public:
    vector<int>store;
    unordered_map<int,int>dict;
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        auto it = dict.find(val);
        if(it != dict.end())
            return false;

        store.push_back(val);
        dict[val] = store.size()-1;
        return true;
    }
    
    bool remove(int val) {
        auto it = dict.find(val);
        if(it == dict.end())
            return false;
        
        int idx = dict[val];
        store[idx] = store[store.size()-1];
        dict[store[idx]] = idx;
        dict.erase(val);
        store.pop_back();
        return true;
    }
    
    int getRandom() {
        return store[rand()%(store.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */