class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row>=m or col>=n) return INT_MAX;
        if(row==m-1 and col==n-1) return grid[row][col];
        if(memo[row][col] != -1) return memo[row][col];
        return memo[row][col]= grid[row][col] + min(dp(grid, row+1, col), dp(grid, row, col+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memo.resize(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return dp(grid, 0, 0);
    }
};