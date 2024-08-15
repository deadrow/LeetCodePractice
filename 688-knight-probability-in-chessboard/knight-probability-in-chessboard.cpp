class Solution {
public:
    vector<pair<int,int>>directions{{2,-1},{2,1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
    vector<vector<vector<double>>>memo;
    double dp(int n, int k, int row, int col){
        if(row<0 or row>=n or col<0 or col>=n or k<0) return 0;
        if(row>=0 and row<n and col>=0 and col<n and k==0) return 1;
        if(memo[row][col][k] != -1) return memo[row][col][k];
        double count=0;
        for(const auto& it : directions){
            count += dp(n, k-1, row+it.first, col+it.second)/8;
        }
        return memo[row][col][k] = count;
    }
    double knightProbability(int n, int k, int row, int column) {
        memo.resize(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return dp(n, k, row, column);
    }
};