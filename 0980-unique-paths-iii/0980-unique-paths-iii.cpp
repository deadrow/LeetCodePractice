class Solution {
public:
    int count = 0;
    int dest_i = -1;
    int dest_j = -1;
    int empty = 1;
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        if(i < 0 || j < 0 || i >=m || j >= n || grid[i][j] < 0)
            return;
        
        if(i == dest_i && j == dest_j)
        {
            if(empty == 0)
                count++;
            return;
        }
        
        grid[i][j] = -2;
        empty--;
        for(auto it : directions)
        {
            int nRow = i + it.first;
            int nCol = j + it.second;
            dfs(grid, nRow, nCol, m, n);
        }
        grid[i][j] = 0;
        empty++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>>visited;
        
        queue<pair<int,int>>bfs;

        int start_i = -1;
        int start_j = -1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    start_i = i;
                    start_j = j;
                }
                else if(grid[i][j] == 2)
                {
                    dest_i = i;
                    dest_j = j;
                }
                else if(grid[i][j] == 0)
                    empty++;
            }
        }
        
        dfs(grid, start_i, start_j, m, n);
        return count;
        
    }
};