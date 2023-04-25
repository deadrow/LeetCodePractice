class SmallestInfiniteSet {
public:
    unordered_set<int> nums;
    priority_queue<int, vector<int>, greater<>>pq;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            nums.insert(i);
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int x = pq.top();
        pq.pop();
        nums.erase(x);
        return x;
    }
    
    void addBack(int num) {
        if(nums.find(num) == nums.end())
        {
            nums.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */