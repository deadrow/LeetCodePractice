class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> cache;
        
        for(auto it : nums)
            cache[it]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> min_heap;
        
        for(auto it : cache)
        {
            min_heap.push({it.second, it.first});
            
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<int> res;
        while(!min_heap.empty())
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return res;
    }
};