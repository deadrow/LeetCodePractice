class Solution {
public:
    vector<pair<int,int>>directions{{1,0},{-1,0},{0,-1},{0,1}};
    int m=0;
    int n=0;
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>>bfs;
        bfs.push({i,j});
        // grid[i][j] = '0';

        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();

            if(grid[cur.first][cur.second] == '0') continue;
            grid[cur.first][cur.second] = '0';

            for(auto [row,col] : directions){
                int nRow = cur.first + row;
                int nCol = cur.second + col;
                if(nRow>=0 and nRow< m and nCol>=0 and nCol<n and grid[nRow][nCol] == '1'){
                    // grid[nRow][nCol] = '0';
                    bfs.push({nRow, nCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        this->m = m;
        this->n = n;
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};