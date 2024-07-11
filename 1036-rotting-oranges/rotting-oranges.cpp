class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<pair<int,int>>bfs;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2)
                    bfs.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(!fresh) return 0;

        int time=0;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i=0;i<size;i++){
                auto cur = bfs.front();
                bfs.pop();
                for(auto it : directions){
                    int nRow = it.first + cur.first;
                    int nCol = it.second + cur.second;
                    if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and grid[nRow][nCol] == 1){
                        grid[nRow][nCol] = 2;
                        bfs.push({nRow, nCol});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh > 0 ? -1 : time-1;
    }
};