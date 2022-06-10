class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& nums, int cur_i, int n)
    {
        if(cur_i >= n)
            return 0;
        
        if(memo[cur_i] != -1)
            return memo[cur_i];
        
        int ans = INT_MAX-1;
        for(int pos=cur_i+1;pos<=cur_i+nums[cur_i];pos++)
        {
            int res = 1 + dp(nums, pos, n);
            ans = min(ans, res);
        }
        
        return memo[cur_i] = ans;
    }
    
    int jump(vector<int>& nums)
    {
        memo.resize(nums.size(), -1);
        return dp(nums, 0, nums.size()-1);
    }
};