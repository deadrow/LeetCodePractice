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

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
private:
    vector<int>parent;
    vector<int>rank;
    int roots{0};
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>>quriesWithIdx(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            quriesWithIdx[i] = queries[i];
            quriesWithIdx[i].push_back(i);
        }

        sort(quriesWithIdx.begin(), quriesWithIdx.end(), [](const auto& a, const auto& b){
            return a[2] < b[2];
        });

        sort(edgeList.begin(), edgeList.end(), [](const auto& a, const auto& b){
            return a[2] < b[2];
        });

        UnionFind uf(n);
        vector<bool>ret(quriesWithIdx.size());

        int j = 0;
        for(int i=0;i<quriesWithIdx.size();i++)
        {
            while(j < edgeList.size() && edgeList[j][2] < quriesWithIdx[i][2])
            {
                uf.unionSet(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            
            ret[quriesWithIdx[i][3]] = uf.connected(quriesWithIdx[i][0], quriesWithIdx[i][1]);
        }

        return ret;
    }
};