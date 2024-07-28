class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>>memo;
    int dfs(vector<vector<int>>& matrix, int row, int col){
        int m = matrix.size();
        int n = matrix[0].size();
        if(memo[row][col] != -1) return memo[row][col];
        int count=1;
        for(auto& it : directions){
            int nRow = row + it.first;
            int nCol = col + it.second;
            if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and matrix[nRow][nCol] > matrix[row][col])
                count = max(count, 1 + dfs(matrix, nRow, nCol));
        }

        return memo[row][col]=count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxPath = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        memo.resize(m, vector<int>(n, -1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                maxPath = max(maxPath, dfs(matrix, i, j));
        return maxPath;
    }
};