class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<vector<int>>>memo;
    int MOD = 1e9+7;
    int dp(int m, int n, int maxMove, int row, int col){
        if(maxMove < 0) return 0;
        if(row>=m or row<0 or col >=n or col<0) return 1;
        if(memo[row][col][maxMove]!= -1) return memo[row][col][maxMove];
        int count=0;
        for(const auto& it : directions){
            count = (count + dp(m, n, maxMove-1, row+it.first, col+it.second))%MOD;
        }
        return memo[row][col][maxMove] = count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return dp(m, n, maxMove, startRow, startColumn);
    }
};