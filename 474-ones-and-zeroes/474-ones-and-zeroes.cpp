class Solution {
public:
    vector<vector<vector<int>>>memo;
    pair<int, int> count(string str)
    {
        int zeros = 0;
        int ones = 0;
        for(auto it : str)
        {
            if(it == '0')
                zeros++;
            else
                ones++;
        }
        
        return {zeros, ones};
    }
    
    int dp(vector<string>& strs, int i, int m, int n)
    {
        if(m == 0 && n == 0)
            return 0;
        
        if(i < 0)
        {
            return 0;
        }

        if(memo[i][m][n] != -1)
            return memo[i][m][n];
        
        pair<int, int> counts = count(strs[i]);
        
        int sum1 = 0;
        if(counts.first <= m && counts.second <= n)
        {
            sum1 += dp(strs, i-1, m-counts.first, n-counts.second)+1;
        }

        int sum2 = dp(strs, i-1, m, n);
        return memo[i][m][n] = max(sum1, sum2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int size = strs.size();
        memo.resize(size+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return dp(strs, size-1, m, n);
    }
};