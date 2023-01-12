class Solution {
public:
    vector<bool> visited;
    int dfs(unordered_map<int, vector<int>>& adjList, int src, vector<bool>& hasApple)
    {
        visited[src] = true;

        int totalTime = 0;
        for(auto it : adjList[src])
        {
            if(!visited[it])
            {
                int ret = dfs(adjList, it, hasApple);
                
                if(ret || hasApple[it])
                    totalTime = totalTime + ret + 2;
            }
        }
        
        return totalTime;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adjList;
        
        visited.resize(n, false);
           
        for(auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        return dfs(adjList, 0, hasApple);
    }
};