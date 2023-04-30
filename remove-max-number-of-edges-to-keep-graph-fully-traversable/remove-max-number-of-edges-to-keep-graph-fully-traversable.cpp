class UnionFind
{
public:
    UnionFind(int n)
        : parentAlice(n)
        , parentBob(n)
        , rootsAlice(n)
        , rootsBob(n)
    {
        for(int i=0;i<n;i++)
        {
            parentAlice[i] = i;
            parentBob[i] = i;
        }
    }

    int findAlice(int x)
    {
        if(x == parentAlice[x])
            return x;

        return parentAlice[x] = findAlice(parentAlice[x]);
    }

    int findBob(int x)
    {
        if(x == parentBob[x])
            return x;

        return parentBob[x] = findBob(parentBob[x]);
    }

    void unionSet(int x, int y, int type)
    {
        if(type == 1)
        {
            int rootX = findAlice(x);
            int rootY = findAlice(y);
            if(rootX != rootY)
            {
                rootsAlice--;
                parentAlice[rootY] = rootX;
            }
        }
        else if(type == 2)
        {
            int rootX = findBob(x);
            int rootY = findBob(y);
            if(rootX != rootY)
            {
                rootsBob--;
                parentBob[rootY] = rootX;
            } 
        }
        else
        {
            int rootX = findAlice(x);
            int rootY = findAlice(y);
            if(rootX != rootY)
            {
                rootsAlice--;
                parentAlice[rootY] = rootX;
            }

            rootX = findBob(x);
            rootY = findBob(y);
            if(rootX != rootY)
            {
                rootsBob--;
                parentBob[rootY] = rootX;
            }
        }
    }

    bool connected(int x, int y , int type)
    {
        if(type == 1)
            return findAlice(x) == findAlice(y);
        else if(type == 2)
            return findBob(x) == findBob(y);
        return (findAlice(x) == findAlice(y) && findBob(x) == findBob(y));
    }

    int countRootsAlice()
    {
        return rootsAlice;
    }

    int countRootsBob()
    {
        return rootsBob;
    }
private:
    vector<int>parentAlice;
    vector<int>parentBob;
    int rootsAlice;
    int rootsBob;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind uf(n+1);

        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return a[0] > b[0];
        });

        int maxEdges = 0;
        for(auto it : edges)
        {
            if(!uf.connected(it[1], it[2], it[0]))
                uf.unionSet(it[1], it[2], it[0]);
            else
                maxEdges++;
        }

        if(uf.countRootsAlice() != 2 || uf.countRootsBob() != 2)
            return -1;

        return maxEdges;
    }
};