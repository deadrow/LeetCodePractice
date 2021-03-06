class Solution {
public:
    int minInsertions(string s) {
        // FIND longest panlindromic subsequence first
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1));
        
        string first = s;
        string second = s;
        reverse(second.begin(), second.end());
        
        int maxLength = INT_MIN;
        int x = -1;
        int y = -1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(first[i-1] == second[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return n- dp[n][n];
    }
};