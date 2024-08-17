class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>bfs;
        bfs.push({0,0,0});
        vector<vector<bool>>visited(m, vector<bool>(n));

        while(!bfs.empty()){
            auto cur = bfs.top(); bfs.pop();
            if(cur[1] == m-1 and cur[2] == n-1)
                return cur[0];
            if(visited[cur[1]][cur[2]]) continue;
            visited[cur[1]][cur[2]] = true;
            int time = cur[0];
            for(const auto& it : directions){
                int nRow = it.first + cur[1];
                int nCol = it.second + cur[2];
                if(nRow>=0 and nRow<m and nCol>=0 and nCol<n){
                    if(grid[nRow][nCol] <= time+1)
                        bfs.push({time+1, nRow, nCol});
                    else if(grid[nRow][nCol] > time+1){
                        int diff = grid[nRow][nCol]-time;
                        if(diff & 1) // if the diff is even we need one more step
                            bfs.push({time+diff, nRow, nCol});
                        else
                            bfs.push({time+diff+1, nRow, nCol});
                    }
                }
            }
        }
        
        return -1;
    }
};