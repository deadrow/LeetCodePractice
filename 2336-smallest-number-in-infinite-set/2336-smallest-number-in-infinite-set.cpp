class SmallestInfiniteSet {
public:
    set<int> nums;
    int cur = 1;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if(!nums.empty())
        {
            int x = *nums.begin();
            nums.erase(x);
            return x;
        }
        
        return cur++;
    }
    
    void addBack(int num) {
        if(num < cur)
            nums.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */