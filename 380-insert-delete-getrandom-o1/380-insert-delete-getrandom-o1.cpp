class RandomizedSet {
public:
    unordered_map<int, int> data;
    vector<int> store;
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        auto it = data.find(val);
        if(it == data.end())
        {
            store.push_back(val);
            data[val] = store.size()-1;
            return true;
        }

        return false;
    }

    bool remove(int val) {
        auto it = data.find(val);
        if(it != data.end())
        {
            int lastElem = store[store.size()-1];
            int idx = data[val];
            store[idx] = lastElem;
            data[lastElem] = idx;
            store.pop_back();
            data.erase(it);
            return true;
        }
            
        return false;
    }
    
    int getRandom() {
        return store[rand()%store.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */