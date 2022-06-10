class Solution {
public:
    vector<int>memo;
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
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n+1,-1);
        return dp(nums, 0, -1, n);
    }
};