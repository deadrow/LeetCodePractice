class UnionFind
{
public:
    
    UnionFind(int size)
        : rank(size)
        , root(size)
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
        }
    }
    
private:
    vector<int>root;
    vector<int>rank;
};

class Solution {
public:
    int goodPaths = 0;
    void dfs(unordered_map<int, vector<int>>& adjList, vector<int>& vals, int start, int cur, vector<bool>& visited)
    {
        if(start != cur && vals[start] == vals[cur])
            goodPaths++;
        
        visited[cur] = true;
        
        for(auto it : adjList[cur])
        {
            if(!visited[it] && vals[it] <= vals[start])
                dfs(adjList, vals, start, it, visited);
        }
    }
    
    // dfs solution
    int numberOfGoodPaths1(vector<int>& vals, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>>adjList;
        for(auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        for(auto it : adjList)
        {
            vector<bool>visited(vals.size());
            dfs(adjList, vals, it.first, it.first, visited);
        }
        
        return (goodPaths/2) + vals.size();
    }
    
    // Union Find solution
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
 
        vector<vector<int>>adjList(n);
        for(auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        map<int, vector<int>>valsToNode;
        for(int i=0;i<vals.size();i++)
            valsToNode[vals[i]].push_back(i);
        
         UnionFind uf(n);
        
        for(auto& [val, nodes] : valsToNode)
        {
            for(auto u : nodes)
            {
                for(auto v : adjList[u])
                {
                    if(vals[u] >= vals[v])
                        uf.unionSet(u, v);
                }
            }
            
            unordered_map<int, int>group;
            for(auto u : nodes)
            {
                group[uf.find(u)]++;
            }
            
            for(auto& [_, size] : group)
            {
                goodPaths += (size*(size+1)/2);
            }
        }
        
        return goodPaths;
    }
};