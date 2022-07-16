class Solution {
public:
    int MOD = 1000000007;
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<vector<int>>> memo;
    int dfs(int m, int n, int k, int row, int col)
    {
        if(row < 0 || col < 0 || row == m || col == n)
            return 1;
        
        if(k == 0)
            return 0;
        
        if(memo[row][col][k] != -1)
            return memo[row][col][k];
        
        int count = 0;
        for(auto it : directions)
        {
            int nRow = row + it.first;
            int nCol = col + it.second;
            
            count = (count + dfs(m, n, k-1, nRow, nCol)) % MOD;
        }
        
        return memo[row][col][k] = count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        
        return dfs(m, n, maxMove, startRow, startColumn);
    }
};