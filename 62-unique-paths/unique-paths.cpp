class Solution {
public:
    vector<vector<int>>memo;
    int dp(int row, int col, int m, int n){
        if(row >= m or col>= n) return 0;
        if(row == m-1 and col == n-1) return 1;
        if(memo[row][col] != -1) return memo[row][col];
        return memo[row][col]=dp(row, col+1, m , n) + dp(row+1, col, m , n);
    }
    int uniquePaths(int m, int n) {
        memo.resize(m+1, vector<int>(n+1, -1));
        return dp(0, 0, m, n);
    }
};