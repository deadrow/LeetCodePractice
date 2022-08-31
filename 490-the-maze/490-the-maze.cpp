class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        queue<pair<int,int>> bfs;
        bfs.push({start[0],start[1]});
        visited[start[0]][start[1]] = true;
        
        while(!bfs.empty())
        {
            int row = bfs.front().first;
            int col = bfs.front().second;
            bfs.pop();

            if(row == destination[0] && col == destination[1])
                return true;

            for(auto it : directions)
            {
                int nRow = row + it.first;
                int nCol = col + it.second;
                
                while(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && maze[nRow][nCol] == 0)
                {
                    nRow += it.first;
                    nCol += it.second;
                }
                
                // ball hit the wall. So back up 1 step
                if(!visited[nRow-it.first][nCol-it.second])
                {
                    bfs.push({nRow-it.first, nCol-it.second});
                    visited[nRow-it.first][nCol-it.second] = true;
                }
            }
        }
        
        return false;
    }
};