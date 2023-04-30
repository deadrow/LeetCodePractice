class UnionFind
{
public:
    UnionFind(int n)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                parent[i].push_back(j);
            }
        }

        roots[0] = n; // alice parents
        roots[1] = n; // bob parents
    }

    int find(int x, int type)
    {
        if(x == parent[type-1][x])
            return x;

        return parent[type-1][x] = find(parent[type-1][x], type);
    }

    void unionSet(int x, int y, int type)
    {
        if(type == 1 || type == 2)
        {
            int rootX = find(x, type);
            int rootY = find(y, type);
            if(rootX != rootY)
            {
                roots[type-1]--;
                parent[type-1][rootY] = rootX;
            }
        }
        else
        {
            int rootX = find(x, 1);
            int rootY = find(y, 1);
            if(rootX != rootY)
            {
                roots[0]--;
                parent[0][rootY] = rootX;
            }

            rootX = find(x, 2);
            rootY = find(y, 2);
            if(rootX != rootY)
            {
                roots[1]--;
                parent[1][rootY] = rootX;
            }
        }
    }

    bool connected(int x, int y , int type)
    {
        if(type == 1 || type == 2)
            return find(x, type) == find(y, type);
        return (find(x, 1) == find(y, 1) && find(x, 2) == find(y, 2));
    }

    int countRoots(int type)
    {
        return roots[type-1];
    }
private:
    vector<int> parent[2];
    int roots[2];
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind uf(n+1);

        int maxEdges = 0;
        for(const auto& it : edges)
        {
            if(it[0] == 3)
            {
                if(!uf.connected(it[1], it[2], it[0]))
                    uf.unionSet(it[1], it[2], it[0]);
                else
                    maxEdges++;
            }
        }

        for(const auto& it : edges)
        {
            if(it[0] != 3)
            {
                if(!uf.connected(it[1], it[2], it[0]))
                    uf.unionSet(it[1], it[2], it[0]);
                else
                    maxEdges++;
            }
        }

        if(uf.countRoots(1) != 2 || uf.countRoots(2) != 2)
            return -1;

        return maxEdges;
    }
};