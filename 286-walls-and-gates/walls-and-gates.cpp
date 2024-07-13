class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int INF = 2147483647;
        int m = rooms.size();
        int n = rooms[0].size();
        queue<vector<int>>bfs;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j] == 0)
                    bfs.push({i,j,0});
            }
        }

        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
                        
            for(auto& it : directions){
                int nRow = it.first + cur[0];
                int nCol = it.second + cur[1];
                if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and rooms[nRow][nCol] == INF){
                    rooms[nRow][nCol] = cur[2]+1;
                    bfs.push({nRow, nCol, cur[2]+1});
                }
            }
        }
    }
};