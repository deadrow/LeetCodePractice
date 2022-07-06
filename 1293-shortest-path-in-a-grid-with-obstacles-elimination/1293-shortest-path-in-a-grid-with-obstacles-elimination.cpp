class Solution {
public:
    struct Edge
    {
        int row;
        int col;
        int obstacles;
        int steps;
    };
    
    vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<Edge> bfs;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1)));
        
        bfs.push({0,0,k});
        visited[0][0][0] = true;
        
        int steps = 0;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                auto cur = bfs.front();
                bfs.pop();
                
                if(cur.row == m-1 && cur.col == n-1)
                    return steps;
                
                for(auto it : directions)
                {
                    int nRow = cur.row + it.first;
                    int nCol = cur.col + it.second;
                    int nObstacles = cur.obstacles;

                    if(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && nObstacles >= 0)
                    {
                        if(grid[nRow][nCol] == 1)
                        {
                            nObstacles--;
                        }
                        
                        if(nObstacles >= 0 && !visited[nRow][nCol][nObstacles])
                        {
                            visited[nRow][nCol][nObstacles] = true;
                            bfs.push({nRow, nCol, nObstacles});
                        }
                    }
                }
            }

            steps++;
        }
        
        return -1;
    }
};