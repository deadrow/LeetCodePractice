class Solution {
public:
    vector<int> disc, low;
    vector<vector<int>> result;
    
    void dfs(int idx, int parent, vector<vector<int>> &edges, int time)
    {
        if(disc[idx] >= 0)
            return;
        
        disc[idx] = low[idx] = time++;

        for (auto it : edges[idx])
        {
            if (it == parent)
                continue;

            dfs(it, idx, edges, time);
            
            // If there is a cycle found, the low value of adjecent node
            // will be less than current so update with low value and
            // if we reach a case where low value is greater that discovery
            // value it means it is outside cycle and must be SCC
            low[idx] = min(low[idx], low[it]);
            if (low[it] > disc[idx])
            {
                result.push_back({idx, it});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> edges(n);
        for(auto it : connections)
        {
            edges[it[0]].push_back(it[1]);
            edges[it[1]].push_back(it[0]);
        }

        disc.resize(n, -1);
        low.resize(n, -1);

        int time = 0;
        
        dfs(0, -1, edges, time);
        
        return result;
    }
};