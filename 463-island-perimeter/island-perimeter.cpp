class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>bfs;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])
                    bfs.push({i,j});
            }
        }

        int sides=0;
        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();

            if(grid[cur.first][cur.second] == -2) continue;
            grid[cur.first][cur.second] = -2;

            for(auto [row, col] : directions){
                int nRow = row + cur.first;
                int nCol = col + cur.second;
                if(nRow <0 or nRow>=m or nCol<0 or nCol>=n)
                    sides++;
                else if(nRow>=0 and nRow<m and nCol>=0 and nCol<n) {
                    if(grid[nRow][nCol] == 0)
                        sides++;
                    else if(grid[nRow][nCol]==1){
                        bfs.push({nRow, nCol});
                    }
                }
            }
        }

        return sides;
    }
};