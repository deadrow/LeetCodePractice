class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& nums, int cur_i, int n)
    {
        if(cur_i >= n)
            return 0;
        
        if(memo[cur_i] != -1)
            return memo[cur_i];
        
        int cur = INT_MAX;
        
        for(int i=cur_i+1;i<=cur_i+nums[cur_i];i++)
        {
            int ret = dp(nums, i, n);
            if(ret != INT_MAX)
                cur = min(cur, ret+1);
        }
        
        return memo[cur_i] = cur;
    }
    int jump(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dp(nums,0, nums.size()-1);
    }
};