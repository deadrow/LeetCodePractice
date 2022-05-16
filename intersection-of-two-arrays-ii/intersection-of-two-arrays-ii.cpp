class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cache;
        for(auto it : nums1)
        {
            cache[it]++;
        }
        
        vector<int> res;
        for(auto it : nums2)
        {
            if(cache.find(it) != cache.end() && cache[it] > 0)
            {
                res.push_back(it);
                cache[it]--;
            }
        }
        
        return res;
    }
};