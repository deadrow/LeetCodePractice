class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{1,0}};
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row==m-1 and col==n-1) return grid[m-1][n-1];
        if(memo[row][col] != -1) return memo[row][col];
        int res=INT_MAX;
        for(auto it : directions){
            int nRow = it.first + row;
            int nCol = it.second + col;
            if(row>=0 and row < m and col>=0 and col<n){
                int cur = dp(grid, nRow, nCol);
                if(cur != INT_MAX)
                    res = min(res, grid[row][col] + cur);
            }
        }
        return memo[row][col]=res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memo.resize(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return dp(grid, 0, 0);
    }
};