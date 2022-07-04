class Solution {
public:
    int m;
    int n;
    vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    vector<vector<int>> grid;
    vector<vector<int>> dist;
    vector<vector<int>> reach;
    
    void bfs(int row, int col)
    {
        queue<pair<int, int>> bfs;
        bfs.push({row, col});
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[row][col] = true;

        int step = 1;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                auto cur = bfs.front();
                bfs.pop();
                
                for(auto it : directions)
                {
                    int nRow = cur.first + it.first;
                    int nCol = cur.second + it.second;
                    
                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                       !visited[nRow][nCol] && grid[nRow][nCol] == 0)
                    {
                        dist[nRow][nCol] += step;
                        reach[nRow][nCol]++;
                        visited[nRow][nCol] = true;
                        bfs.push({nRow, nCol});
                    }
                }
            }
            step++;
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        
        this->grid = grid;
        
        dist.resize(m, vector<int>(n));
        reach.resize(m, vector<int>(n));
        
        int buildings = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    buildings++;
                    bfs(i, j);
                }
            }
        }

        int minDist = INT_MAX;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(reach[i][j] == buildings && grid[i][j] == 0)
                {
                    minDist = min(minDist,dist[i][j]);
                }
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};