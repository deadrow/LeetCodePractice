class Solution {
public:
    int MOD = 1000000007;
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<vector<int>>> memo;
    int dfs(int m, int n, int k, int row, int col)
    {
        if(k == 1)
        {
           // check all 4 sides
            int count = 0;
            if(row + 1 == m)
                count++;
            
            if(row-1 < 0)
                count++;
            
            if(col+1 == n)
                count++;
            
            if(col-1 < 0)
                count++;
            
            return count;
        }
        
        if(memo[row][col][k] != -1)
            return memo[row][col][k];
        
        int count = 0;
        for(auto it : directions)
        {
            int nRow = row + it.first;
            int nCol = col + it.second;
            
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n)
            {
                count = (count + dfs(m, n, k-1, nRow, nCol)) % MOD;
            }
        }
        
        return memo[row][col][k] = count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        
        int ans = 0;
        for(int k=1;k<= maxMove;k++)
        {
            ans = (ans + dfs(m, n, k, startRow, startColumn)) % MOD;
        }
        
        return ans;
    }
};