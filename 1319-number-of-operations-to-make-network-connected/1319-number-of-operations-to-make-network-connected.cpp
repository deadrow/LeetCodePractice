class Solution {
public:
    vector<bool>visited;
    
    void dfs(vector<vector<int>>& adjList, int src)
    {
        visited[src] = true;
        for(auto& it : adjList[src])
        {
            if(!visited[it])
                dfs(adjList, it);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
            return -1;
        
        vector<vector<int>>adjList(n);
        
        for(auto it : connections)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        visited.resize(n);
        
        int clusters = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                clusters++;
                dfs(adjList, i);
            }
        }
        
        return clusters == 1 ? 0 : clusters-1;
    }
};