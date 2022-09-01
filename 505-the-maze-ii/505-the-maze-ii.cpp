class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> bfs;
        bfs.push({0,start[0],start[1]});
        
        while(!bfs.empty())
        {
            int curDistance = bfs.top()[0];
            int row = bfs.top()[1];
            int col = bfs.top()[2];
            bfs.pop();
            
            if(visited[row][col])
                continue;
            
            visited[row][col] = true;

            if(row == destination[0] && col == destination[1])
                return curDistance;

            for(auto it : directions)
            {
                int nRow = row + it.first;
                int nCol = col + it.second;
                
                int steps = 0;
                while(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && maze[nRow][nCol] == 0)
                {
                    nRow += it.first;
                    nCol += it.second;
                    steps++;
                }
                

                bfs.push({curDistance+steps, nRow-it.first, nCol-it.second});
            }
        }
        
        return -1;
    }
};