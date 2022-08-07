class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(int row, int col, int m, int n, vector<vector<char>>& grid)
    {
        grid[row][col] = '0';
        for(auto it : directions)
        {
            int nRow = row + it.first;
            int nCol = col + it.second;
            if(nRow >=0 && nRow < m && nCol >= 0 && nCol <n && grid[nRow][nCol] == '1')
                dfs(nRow, nCol, m, n, grid);
        }
//         if(row < m-1 && grid[row+1][col] == '1')
//         {
//             dfs(row+1, col, m, n, grid);
//         }
        
//         if(row > 0 && grid[row-1][col] == '1')
//         {
//             dfs(row-1, col, m, n, grid);
//         }
        
//         if(col < n-1 && grid[row][col+1] == '1')
//         {
//             dfs(row, col+1, m, n, grid);
//         }
        
//         if(col > 0 && grid[row][col-1] == '1')
//         {
//             dfs(row, col-1, m, n, grid);
//         }
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, m, n, grid);
                }
            }
        }
        
        return count;
    }
};