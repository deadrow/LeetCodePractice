class Solution {
public:
    int minScore_ = INT_MAX;
    vector<bool> visited;
    void dfs(vector<vector<pair<int,int>>>& adjList, int src, int dst)
    {
        for(auto& it : adjList[src])
        {
            minScore_ = min(minScore_, it.second);
            if(!visited[it.first])
            {
                visited[it.first] = true;
                dfs(adjList, it.first, dst);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjList(n+1);
        visited.resize(n+1, false);
        for(auto it : roads)
        {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        
        dfs(adjList, 1, n);
        return minScore_;
    }
};