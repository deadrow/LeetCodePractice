class Solution {
public:
    vector<pair<int,int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if(row>=0 and row<m and col>=0 and col<n and grid[row][col]) {
            int cur = grid[row][col];
            grid[row][col] = 0;
            int left = cur + dfs(grid, row, col-1);
            int right = cur + dfs(grid, row, col+1);
            int up = cur + dfs(grid, row-1, col);
            int down = cur + dfs(grid, row+1, col);
            grid[row][col] = cur;
            return max({left, right, up, down});
        }

        return 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) {
                    int ret = dfs(grid, i, j);
                    cout << ret << endl;
                    maxGold = max(maxGold, ret);
                }
            }
        }
        return maxGold;
    }
};