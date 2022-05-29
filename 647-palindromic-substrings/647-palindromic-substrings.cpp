class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        // each letter is itself palindrome
        // so all dp[i][i]  would be true
        // for 2 letters we need to check if
        // i and i+1 is equal
        
        for(int i=0;i<n;i++)
        {
            count++;
            dp[i][i] = true;
        }
            
        
        // for length =2 like "aa"
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                count++;
            }
        }
                
        // for length > 2
        // set i = 0 and j to offset at 2
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    count++;
                }  
            }
        }
        
        return count;
    }
};