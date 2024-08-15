class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<vector<int>>>memo;
    vector<pair<int,int>>directions{{2,-1},{2,1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
    int dp(vector<vector<int>>& grid, int row, int col, int n){
        if(row <0 or row>=grid.size() or col<0 or col>=grid[0].size() or !grid[row][col]) return 0;
        if(n==0) return 1;
        if(memo[row][col][n] != -1) return memo[row][col][n];
        int count=0;
        for(const auto& it : directions){
            int nRow = row + it.first;
            int nCol = col + it.second;
            count = (count + dp(grid, nRow, nCol, n-1)) % MOD;
        }
        return memo[row][col][n]=count;
    }
    int knightDialer(int n) {
        vector<vector<int>>grid{{1,1,1},{1,1,1},{1,1,1},{0,1,0}};
        int count=0;
        memo.resize(4, vector<vector<int>>(3, vector<int>(n+1, -1)));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    count = (count + dp(grid, i, j, n-1)) % MOD;
                }
            }
        }
        return count;
    }
};