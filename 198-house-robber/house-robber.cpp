class Solution {
public:
    // top down solution
    vector<int>memo;
    int dp(vector<int>& nums, int i)
    {
        if(i >= nums.size())
            return 0;
        if(memo[i] != -1)
            return memo[i];

        int take = nums[i] + dp(nums, i+2);
        int leave = dp(nums, i+1);
        return memo[i] = max(take, leave);
    }
    int rob1(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dp(nums, 0);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), 0);
        if(nums.size() < 2)
            return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};