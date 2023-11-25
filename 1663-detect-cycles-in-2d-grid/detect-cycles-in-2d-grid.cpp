class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};

    bool containsCycle(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] < 'a')
                    continue;
                queue<pair<int,int>>bfs;
                char ch = grid[i][j];
                bfs.push({i,j});

                while(!bfs.empty())
                {
                    auto v = bfs.front();
                    int r = v.first;
                    int c = v.second;
                    bfs.pop();

                    if(grid[r][c] < 'a') return true;

                    grid[r][c] -= 26;

                    for(auto it : directions)
                    {
                        int nr = r + it.first;
                        int nc = c + it.second;
                        if(nr >= 0 and nr < m and nc >=0 and nc < n and grid[nr][nc] == ch)
                        {
                            bfs.push({nr,nc});
                        } 
                    }
                }
            }
        }

        return false;
    }
};