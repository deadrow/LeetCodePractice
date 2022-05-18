class Solution {
public:
    vector<int> disc, low;
    vector<bool> visited;
    vector<vector<int>> result;
    
    void dfs(int idx, int parent, vector<vector<int>> &edges, int &time)
    {
        disc[idx] = low[idx] = time;
        time++;
        visited[idx] = true;

        for (auto it : edges[idx])
        {
            if (it == parent)
                continue;
            if (visited[it] == true)
            {
                low[idx] = min(low[idx], disc[it]);
            }
            else
            {
                dfs(it, idx, edges, time);
                low[idx] = min(low[idx], low[it]);
                if (low[it] > disc[idx])
                {
                    result.push_back({idx, it});
                }
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
        
        disc.resize(n);
        low.resize(n);
        visited.resize(n);
            
        int time = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, edges, time);
            }
        }
        
        return result;
    }
};