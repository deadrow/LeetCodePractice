class Solution {
public:
    vector<int>memo;
    
    // Old DP solution
    int dp(vector<int>& nums, int cur_i, int prev, int n)
    {
        if(cur_i >= n)
            return 0;
        
        if(memo[prev+1] != -1)
            return memo[prev+1];
        
        int take = 0;
        if(prev == -1 || nums[cur_i] > nums[prev])
            take = 1 + dp(nums, cur_i+1, cur_i, n);
        
        int leave = dp(nums, cur_i+1, prev, n);
        
        return memo[prev+1] = max(take, leave);
    }
    
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n+1,-1);
        return dp(nums, 0, -1, n);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>subSet;
        subSet.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > subSet.back())
                subSet.push_back(nums[i]);
            else
            {
                auto it = lower_bound(subSet.begin(), subSet.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return subSet.size();
    }
};
