class Solution {
public:
// Graph coloring algorithm. Assign colors to vertexes
    // 1 and 0 to nodes
    bool bfs(int u, vector<vector<int>>& adjList, vector<int>& color)
    {
        queue<int>bfs;
        
        bfs.push(u);
        color[u] = 0;
        
        while(!bfs.empty())
        {
            int u = bfs.front();
            bfs.pop();
            
            for(auto it : adjList[u])
            {
                if(color[it] == -1)
                {
                    color[it] = 1 - color[u];
                    bfs.push(it);
                }
                else if(color[u] == color[it])
                    return false;
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adjList(n);
        for(int i=0;i<graph.size();i++)
        {
            for(auto it : graph[i])
            {
                adjList[i].push_back(it);
                adjList[it].push_back(i);
            }
        }

        vector<int> color(n, -1);
        for(int v=0;v<n;v++)
        {
            if(color[v] == -1)
            {
                if(!bfs(v, adjList, color))
                    return false;
            }
        }

        return true;
    }
};