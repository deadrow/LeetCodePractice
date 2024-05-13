class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>>bfs;
        bfs.push({start[0], start[1]});

        set<pair<int,int>>visited;
        visited.insert({start[0], start[1]});

        while(!bfs.empty()) {
            int row = bfs.front().first;
            int col = bfs.front().second;
            bfs.pop();

            if(row == destination[0] and col == destination[1]) return true;

            for(auto& [x,y] : directions) {
                int nRow = row + x;
                int nCol = col + y;

                while(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && maze[nRow][nCol] == 0) {
                    // keep rolling
                    nRow += x;
                    nCol += y;
                }

                // we hit a wall. So move one step back
                nRow -= x;
                nCol -= y;

                if(visited.find({nRow, nCol}) == visited.end()) {
                    visited.insert({nRow, nCol});
                    bfs.push({nRow, nCol});
                }
            }
        }

        return false;
    }
};