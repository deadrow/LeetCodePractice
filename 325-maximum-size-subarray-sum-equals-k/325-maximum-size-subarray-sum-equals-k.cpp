class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1]+nums[i];
        
        unordered_map<int,int> mp;
        
        int count=0;
        int maxLen = 0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] == k)
            {
                maxLen = i+1;
            }
            
            if(mp.find((long)prefix[i]-k) != mp.end())
                maxLen = max(maxLen, i-mp[prefix[i]-k]);
            
            if(mp.find(prefix[i]) == mp.end())
                mp[prefix[i]] = i;
        }
        
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};