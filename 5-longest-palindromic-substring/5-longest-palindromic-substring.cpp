class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0;
        int start = 0;
        int end = 0;
        
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        // each letter is itself palindrome
        // so all dp[i][i]  would be true
        // for 2 letters we need to check if
        // i and i+1 is equal
        
        for(int i=0;i<n;i++)
            dp[i][i] = true;
        
        // for length =2 like "aa"
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                maxLength = 2;
                start = i;
                end = i+1;
            }
        }
                
        // for length > 2
        // set i = 0 and j to offset at 2
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    if(j-i+1 > maxLength)
                    {
                        maxLength = j-i+1;
                        start = i;
                        end = j;
                    }
                }
                    
            }
        }
        
        return s.substr(start, end-start+1);
    }
};