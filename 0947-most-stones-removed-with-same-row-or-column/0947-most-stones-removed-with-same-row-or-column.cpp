class UnionFind
{
public:
    UnionFind(int n)
        : parent(n)
        , rank(n)
        , size(n)
        , root_count(n)
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
            
            root_count--;
        }
    }
    
    int getLargetSize()
    {
        int maxSize = 0;
        for(auto it : size)
        {
            maxSize = max(maxSize, it);
        }
        return maxSize;
    }
    
    int getRootCount() { return root_count; }
private:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
    int root_count;
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