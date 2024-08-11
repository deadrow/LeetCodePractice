class Solution {
public:
    vector<vector<int>>memo;
    int dp(int row, int col, int m, int n){
        if(row >= m or col>= n) return -1;
        if(row == m-1 and col == n-1) return 1;
        if(memo[row][col] != -1) return memo[row][col];
        int down = dp(row, col+1, m , n);
        int right = dp(row+1, col, m , n);
        int sum=0;
        if(down != -1) sum += down;
        if(right != -1) sum += right;
        return memo[row][col]=sum;
    }
    int uniquePaths(int m, int n) {
        memo.resize(m+1, vector<int>(n+1, -1));
        return dp(0, 0, m, n);
    }
};