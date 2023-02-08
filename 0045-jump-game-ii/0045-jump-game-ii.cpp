class Solution {
public:
    vector<int>memo;
    
    // TOP down
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
    int jump1(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dp(nums,0, nums.size()-1);
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
		vector<int>dp(n, INT_MAX);
		
		dp[0] = 0; // because we need 0 steps to reach 0th pos
		
		for(int i=1;i<n;i++)
		{
			int steps = nums[i-1];
			for(int j=i;j<min(n, i+steps);j++)
				dp[j] = min(dp[j], dp[i-1]+1);
		}
		
		return dp[n-1];
    }
};