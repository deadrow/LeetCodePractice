class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> cache;
        for(auto it : nums1)
        {
            cache.insert(it);
        }
        
        vector<int> res;
        for(auto it : nums2)
        {
            if(cache.find(it) != cache.end())
            {
                res.push_back(it);
                cache.erase(it);
            }
        }
        
        return res;
    }
};