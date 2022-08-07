class Solution {
public:
    int MOD = 1000000007;
    int countVowelPermutation(int n)
    {
        vector<vector<long>>dp(n, vector<long>(5,1));
        
        for(int i=n-2;i>=0;i--)
        {
            dp[i][0] = dp[i+1][1] % MOD;
            dp[i][1] = (dp[i+1][0] + dp[i+1][2]) % MOD;
            dp[i][2] = (dp[i+1][0] + dp[i+1][1] + dp[i+1][3] + dp[i+1][4]) % MOD;
            dp[i][3] = (dp[i+1][2] + dp[i+1][4]) % MOD;
            dp[i][4] = dp[i+1][0] % MOD;
        }
        
        long long count = 0;
        for(int i=0;i<5;i++)
        {
            count += dp[0][i];
        }
        
        return count % MOD;
    }
};