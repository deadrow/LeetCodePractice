class UnionFind
{
public:
    UnionFind(int n)
        : parent(n)
        , rank(n)
        , roots(n)
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

            roots--;
        }
    }

    int countRoots()
    {
        return roots;
    }
private:
    vector<int>parent;
    vector<int>rank;
    int roots{0};
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

        UnionFind uf(strs.size());

        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                int diffs = 0;
                for(int k=0;k<strs[i].size();k++)
                {
                    if(strs[i][k] != strs[j][k])
                        diffs++;
                }

                if(diffs == 0 || diffs == 2)
                    uf.unionSet(i, j);
            }
        }

        return uf.countRoots();
    }
};