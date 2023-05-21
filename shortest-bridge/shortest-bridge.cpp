class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>>bfs;
    pair<int,int> findFirst(vector<vector<int>>& grid, int n) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    return pair<int,int>(i,j);
                }
            }
        }

        return pair<int,int>(-1,-1);
    };

    void mark(vector<vector<int>>& grid, int r, int c, int n)
    {
        grid[r][c] = 2;
        bfs.push({r,c});
        for(auto& it : directions)
        {
            int nRow = r + it.first;
            int nCol = c + it.second;
            if(nRow >=0 && nRow < n && nCol >=0 && nCol < n && grid[nRow][nCol] == 1)
            {
                mark(grid, nRow, nCol, n);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        // first convert 1st island to 2

        auto idx = findFirst(grid, n);
        mark(grid, idx.first, idx.second, n);

        int steps = 0;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                auto cur = bfs.front();
                bfs.pop();
                
                for(auto& it : directions)
                {
                    int nRow = cur.first + it.first;
                    int nCol = cur.second + it.second;
                    if(nRow >=0 && nRow < n && nCol >=0 && nCol < n)
                    {
                        if(grid[nRow][nCol] == 1)
                            return steps;
                        else if(grid[nRow][nCol] == 0)
                        {
                            bfs.push({nRow, nCol});
                            grid[nRow][nCol] = -1;
                        }
                    }
                }
            }

            steps++;
        }
        
        return 0;
    }
};