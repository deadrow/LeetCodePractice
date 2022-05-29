class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, int start, int end)
    {
        if(start == end)
            return 1;
        if(start > end)
            return 1;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int ans = 0;
        if(s[start] == s[end])
            ans = solve(s, start+1, end-1);
        
        return dp[start][end] = ans;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        
        dp.resize(n, vector<int>(n, -1));
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                ans += solve(s, i, j);
            }
        }
        
        return ans;
    }
};