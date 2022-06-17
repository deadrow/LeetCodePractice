class RandomizedSet {
public:
    list<int>data;
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        auto it = find(data.begin(), data.end(), val);
        if(it == data.end())
        {
            data.push_back(val);
            return true;
        }

        return false;
    }

    bool remove(int val) {
        auto it = find(data.begin(), data.end(), val);
        if(it != data.end())
        {
            data.erase(it);
            return true;
        }
            
        return false;
    }
    
    int getRandom() {
        int n = data.size();
        int randIndex = rand()%n;
        auto it = data.begin();
        advance(it, randIndex);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */