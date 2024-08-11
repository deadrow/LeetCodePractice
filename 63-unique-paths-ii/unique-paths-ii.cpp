class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& obstacleGrid, int row, int col){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(row >= m or col>= n or obstacleGrid[row][col]) return 0;
        if(row == m-1 and col == n-1) return 1;
        if(memo[row][col] != -1) return memo[row][col];
        return memo[row][col]=dp(obstacleGrid, row, col+1) +dp(obstacleGrid, row+1, col);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memo.resize(m+1, vector<int>(n+1, -1));
        return dp(obstacleGrid, 0, 0);
    }
};