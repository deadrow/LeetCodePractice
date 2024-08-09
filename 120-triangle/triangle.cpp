class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& triangle, int row, int col){
        if(row >= triangle.size() or col >= triangle[row].size()) return 1e5;
        if(row == triangle.size()-1) return triangle[row][col];
        if(memo[row][col] != -1) return memo[row][col];
        return memo[row][col] = triangle[row][col] + min(dp(triangle, row+1, col), dp(triangle, row+1, col+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memo.resize(triangle.size()+1, vector<int>(triangle[triangle.size()-1].size()+1, -1));
        return dp(triangle, 0, 0);
    }
};