class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& obstacleGrid, int row, int col){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(row >= m or col>= n) return 0;
        if(row == m-1 and col == n-1) return 1;
        if(memo[row][col] != -1) return memo[row][col];
        int sum = 0;
        if(col+1 < n and !obstacleGrid[row][col+1])
            sum += dp(obstacleGrid, row, col+1);
        if(row+1 < m and !obstacleGrid[row+1][col])
            sum += dp(obstacleGrid, row+1, col);
        return memo[row][col]=sum;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] or obstacleGrid[m-1][n-1]) return 0;
        memo.resize(m+1, vector<int>(n+1, -1));
        return dp(obstacleGrid, 0, 0);
    }
};