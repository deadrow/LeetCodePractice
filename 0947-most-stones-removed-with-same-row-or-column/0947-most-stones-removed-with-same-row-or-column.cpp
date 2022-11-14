class UnionFind
{
public:
    UnionFind(int n)
        : parent(n)
        , rank(n)
        , rootCount(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
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
            }
            else if(rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX] += 1;
            }
            
            rootCount--;
        }
    }

    int getRootCount() { return rootCount; }
private:
    vector<int>parent;
    vector<int>rank;
    int rootCount;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones.size());
        
        for(int i=0;i<stones.size();i++)
        {
            for(int j=i+1;j<stones.size();j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.unionSet(i,j);
            }
        }
        
        return stones.size() - uf.getRootCount();
    }
};