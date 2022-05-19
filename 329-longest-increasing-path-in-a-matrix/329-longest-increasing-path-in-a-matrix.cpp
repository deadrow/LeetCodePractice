class Solution {
public:
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int row, int col, int m, int n)
    {
        int ans = 0;
        
        if(dp[row][col] != 0)
            return dp[row][col];
        
        for(auto it : directions)
        {
            int nRow = row + it.first;
            int nCol = col + it.second;
            
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && matrix[nRow][nCol] > matrix[row][col])
            {
                int cur = dfs(matrix, nRow, nCol, m, n);
                ans = max(ans, cur);
            }
        }

        return dp[row][col] = ans+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        dp.resize(m, vector<int>(n));
        
        int total_max = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cur = dfs(matrix, i, j, m, n);
                total_max = max(cur, total_max);
            }
        }
        
        return total_max;
    }
};