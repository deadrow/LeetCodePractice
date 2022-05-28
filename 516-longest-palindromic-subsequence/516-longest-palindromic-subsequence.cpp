class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1));
        
        string first = s;
        string second = s;
        reverse(second.begin(), second.end());
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(first[i-1] == second[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};