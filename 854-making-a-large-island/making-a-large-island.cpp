class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int n=0;
    int dfs(vector<vector<int>>& grid, int row, int col, int color){
        if(row<0 or row>=n or col<0 or col>=n or grid[row][col] != 1)
            return 0;

        grid[row][col] = color;

        int sum=0;
        for(auto it : directions){
            sum += dfs(grid, row+it.first, col+it.second, color);
        }
        return sum+1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        this->n = n;
        int maxArea=0;

        unordered_map<int,int>areaMap; // map of color vs area
        int color = 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int area = dfs(grid, i, j, color);
                    areaMap[color++] = area;
                    maxArea = max(maxArea, area);
                } 
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    unordered_set<int>colorSeen;
                    int curArea = 1;
                    for(auto it : directions){
                        int nRow = it.first + i;
                        int nCol = it.second + j;
                        
                        if(nRow>=0 and nRow<n and nCol>=0 and nCol<n){
                            int color = grid[nRow][nCol];
                            if(color > 1 and !colorSeen.count(color))
                                curArea += areaMap[color];
                                colorSeen.insert(color);
                        }
                    }
                    maxArea = max(maxArea, curArea);
                } 
            }
        }

        return maxArea;
    }
};