class Solution {
public:
    // Top to bottom
    vector<int>memo;
    int dp(vector<int>& nums, int i, int prev)
    {
        if(i >= nums.size())
            return 0;

        if(memo[prev+1] != -1)
            return memo[prev+1];

        int take = 0;
        if(prev == -1 or nums[i] > nums[prev])
            take = 1 + dp(nums, i+1, i);

        int leave = dp(nums, i+1, prev);
        return memo[prev+1] = max(take, leave);
    }

    int lengthOfLIS1(vector<int>& nums) {
        memo.resize(nums.size()+1, -1);
        return dp(nums, 0, -1);
    }

    // bottom up
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        } 

        return *max_element(dp.begin(), dp.end());
    }
};