class Solution {
public:
    vector<vector<optional<int>>>memo;
    int dp(vector<vector<int>>& matrix, int row, int col){
        if(col < 0 or col >=matrix.size()) return INT_MAX;
        if(row == matrix.size()-1) return matrix[row][col];
        if(memo[row][col] != nullopt) return memo[row][col].value_or(0);
        int first = dp(matrix, row+1, col-1);
        int second = dp(matrix, row+1, col);
        int third = dp(matrix, row+1, col+1);
        int minSum = min(first, min(second, third)) + matrix[row][col];
        memo[row][col]= minSum;
        return minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        memo.resize(matrix.size(), vector<optional<int>>(matrix.size(), nullopt));
        for(int i=0;i<matrix.size();i++)
            minSum = min(minSum, dp(matrix, 0, i));
        return minSum;
    }
};