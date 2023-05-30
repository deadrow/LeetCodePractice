class MyHashSet {
public:
    vector<list<int>>table;
    int prime;
    MyHashSet() : prime(10007) {
        table.resize(prime);
    }
    
    int hash(int key) {
        return key % prime;
    }

    auto search(int key) {
        int hashed = hash(key);
        return find(table[hashed].begin(), table[hashed].end(), key);
    }

    void add(int key) {
        int hashed = hash(key);
        if(!contains(key))
            table[hashed].push_back(key);
    }
    
    void remove(int key) {
        int hashed = hash(key);
        auto it = search(key);
        if(it != table[hashed].end())
        {
            table[hashed].erase(it);
        }
    }
    
    bool contains(int key) {
        int hashed = hash(key);
        return search(key) != table[hashed].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */