class UnionFind
{
public:
    
    UnionFind(int size)
        : rank(size)
        , root(size)
        , size(size)
        , count(0)
    {
        for(int i=0;i<size;i++)
        {
            root[i] = size-1;
            rank[i] = 1;
        }
    }
    
    void changeParent(int i)
    {
        root[i] = i;
        count++;
    }
    
    int find(int x)
    {
        if(x == root[x])
            return x;
        
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
                root[rootY] = root[rootX];
            else if(rank[rootY] > rank[rootX])
                root[rootX] = root[rootY];
            else
            {
                root[rootY] = root[rootX];
                rank[rootX] += 1;
            }
            
            count--;
        }
    }
    
    bool isConnected(int x, int y)
    {
        return (find(x) == find(y));
    }
    
    int getRoots()
    {
        return count;
    }
    
private:
    vector<int>root;
    vector<int>rank;
    int count;
    int size;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {

        vector<vector<int>> board(m, vector<int>(n));
        
        vector<int> ret;
        
        UnionFind uf(m*n+1);

        for(int k=0;k<positions.size();k++)
        {
            int i = positions[k][0];
            int j = positions[k][1];
            board[i][j] = 1;
            
            if(uf.find(i*n+j) == m*n)
                uf.changeParent(i*n+j);
            
            if(i-1>=0 && board[i-1][j] == 1)
                uf.unionSet((i-1)*n+j, i*n+j);
                
            if(i+1 < m && board[i+1][j] == 1)
                uf.unionSet((i+1)*n+j, i*n+j);
                
            if(j-1>=0 && board[i][j-1] == 1)
                uf.unionSet(i*n+j-1, i*n+j);
                
            if(j+1<n && board[i][j+1] == 1)
                uf.unionSet(i*n+j+1, i*n+j);
            

            ret.push_back(uf.getRoots());
        }
        
        return ret;
    }
};