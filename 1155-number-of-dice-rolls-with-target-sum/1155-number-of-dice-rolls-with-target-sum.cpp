class Solution {
public:
    int n = 0;
    int MOD = 1000000007;
    vector<vector<int>>memo;
    int dp(int cur_i, int cur_sum, int k, int target)
    {
        if(cur_sum > target)
            return 0;
        
        if(cur_i == n)
        {
            if(cur_sum == target)
                return 1;
            return 0;
        }
        
        if(memo[cur_i][cur_sum] != -1)
            return memo[cur_i][cur_sum];

        int count = 0;
        for(int i=1;i<=k;i++)
        {
            count = (count+dp(cur_i+1, cur_sum + i, k, target)) % MOD;
        }
        
        memo[cur_i][cur_sum] = count;
        return count;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        this->n = n;
        memo.resize(n+1, vector<int>(target+1, -1));
        
        return dp(0, 0, k, target);
    }
};