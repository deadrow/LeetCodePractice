class Solution {
public:
    vector<pair<int,int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        int cur = grid[row][col];
        grid[row][col] = 0;

        int curMax = 0;
        for(auto it : directions) {
            int nRow = row + it.first;
            int nCol = col + it.second;
            if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and grid[nRow][nCol]) {
                curMax = max(curMax, dfs(grid, nRow, nCol));
            }
        }

        grid[row][col] = cur;
        return cur + curMax;
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