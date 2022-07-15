class UnionFind
{
public:
    UnionFind(int n)
        : parent(n)
        , rank(n)
        , size(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }
    }
    
    int find(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            else if(rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
            else
            {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                rank[rootX] += 1;
            }
        }
    }
    
    int getSize(int x)
    {
        int rootX = find(x);
        return size[rootX];
    }
private:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
};

class Solution {
public:
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n)
    {
        if(row < 0 || row >= m || col < 0 || col >=n || grid[row][col] != 1)
            return 0;
        
        grid[row][col] = 0;
        
        int count = 1;
        for(auto it : directions)
        {
            int nRow = row + it.first;
            int nCol = col + it.second;
            count += dfs(grid, nRow, nCol, m, n);
        }
        
        return count;
    }

    /* dfs solution */
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int max_area = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int cur_area = dfs(grid, i, j, m, n);
                    max_area = max(max_area, cur_area);
                }
            }
        }
        
        return max_area;
    }
    
    /* union find solution */
    int maxAreaOfIsland1(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int max_area = 0;
        UnionFind uf(m*n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x = i*n + j; 
                if(grid[i][j] == 1)
                {
                    for(auto it : directions)
                    {
                        int nRow = i + it.first;
                        int nCol = j + it.second;
                        if(nRow < 0 || nRow >= m || nCol < 0 || nCol >=n || grid[nRow][nCol] != 1)
                            continue;
                        uf.unionSet(x, nRow*n + nCol);
                    }
                    
                    int cur_area = uf.getSize(x);
                    max_area = max(max_area, cur_area);
                }
            }
        }
        return max_area;
    }
};