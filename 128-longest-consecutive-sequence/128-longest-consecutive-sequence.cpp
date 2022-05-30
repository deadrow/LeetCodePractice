class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>cache;
        for(auto it : nums)
            cache.insert(it);
        
        int ans = 0;
        for(auto it : cache)
        {
            int cur = it;
            if(cache.find(cur-1) != cache.end())
               continue;
            
            int cur_max = 1;
            while(cache.find(cur+1) != cache.end())
            {
                cur_max++;
                cur++;
            }
            
            ans = max(ans, cur_max);
        }
            
        return ans;
    }
};