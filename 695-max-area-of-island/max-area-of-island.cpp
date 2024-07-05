class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int m=0;
    int n=0;
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row<0 or row>=m or col<0 or col>=n or grid[row][col] != 1)
            return 0;

        grid[row][col] = 2;

        int sum=0;
        for(auto& it : directions){
            sum += dfs(grid, row+it.first, col+it.second);
        }
        return sum+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        this->m = m, this->n = n;
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    maxArea = max(maxArea, dfs(grid, i, j));
                } 
            }
        }
        return maxArea;
    }
};