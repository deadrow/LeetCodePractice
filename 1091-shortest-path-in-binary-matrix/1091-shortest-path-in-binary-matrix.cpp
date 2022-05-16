class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        
        queue<pair<int, int>> bfs;
        vector<vector<int>> visited(n, vector<int>(n));
        
        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        
        bfs.push({0,0});
        visited[0][0] = true;
        
        int steps=1;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                int row = bfs.front().first;
                int col = bfs.front().second;
                bfs.pop();
                
                if(row == n-1 && col == n-1)
                    return steps;
                
                for(auto it : directions)
                {
                    int nRow = row + it.first;
                    int nCol = col + it.second;
                    
                    if(nRow >= 0 && nRow < n && nCol >=0 && nCol < n && !grid[nRow][nCol] && !visited[nRow][nCol])
                    {
                        visited[nRow][nCol] = true;
                        bfs.push({nRow, nCol});
                    }
                }
            }

            steps++;
        }
        
        return -1;
    }
};