class UnionFind
{
public:
    UnionFind(int size)
        : root(size)
        , rank(size)
        , roots(size)
    {
        for(int i=0;i<size;i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x)
    {
        if(x == root[x])
        {
            return x;
        }
        
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            roots--;
        }
    }
    
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
    
    int differentRoots()
    {
        return roots;
    }
    
private:
    vector<int> root;
    vector<int> rank;
    int roots;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] && i!=j)
                {
                    uf.unionSet(i, j);
                }
            }
        }
        
        return uf.differentRoots();
    }
};