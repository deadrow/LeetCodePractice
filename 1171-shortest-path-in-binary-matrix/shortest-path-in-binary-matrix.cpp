class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        queue<pair<int,int>>bfs;
        set<pair<int,int>>visited;
        bfs.push({0,0});

        int steps=1;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i=0;i<size;i++){
                auto cur = bfs.front();
                bfs.pop();

                if(cur.first == n-1 and cur.second == n-1)
                    return steps;
                if(visited.count(cur)) continue;
                visited.insert(cur);

                for(auto [row,col] : directions){
                    int nRow = cur.first + row;
                    int nCol = cur.second + col;
                    if(nRow>=0 and nRow<n and nCol>=0 and nCol<n and !grid[nRow][nCol]){
                        bfs.push({nRow, nCol});
                    }
                }
            }
            
            steps++;
        }

        return -1;
    }
};