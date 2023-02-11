class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<vector<int>>bfs;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    bfs.push({i,j});
            }
        }
        
        if(bfs.empty() || bfs.size() == n*n)
            return -1;
        
        int dist = 0;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                int row = bfs.front()[0];
                int col = bfs.front()[1];
                bfs.pop();

                for(auto it : directions)
                {
                    int nRow = row + it.first;
                    int nCol = col + it.second;

                    if(nRow >= 0 && nRow < n && nCol >=0 && nCol < n && !grid[nRow][nCol])
                    {
                        bfs.push({nRow, nCol});
                        grid[nRow][nCol] = 1;
                    }
                }
            }
            dist++;
        }
        
        return dist-1;
    }
};