class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1));
        
        string first = s;
        string second = s;
        reverse(second.begin(), second.end());
        
        string res;
        int maxLength = 0;
        int end = -1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(first[i-1] == second[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(maxLength < dp[i][j])
                    {
                        if(i-dp[i][j] == n-j)
                        {
                            maxLength = dp[i][j];
                            end = i;
                        }
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return s.substr(end-maxLength, maxLength);
    }
};