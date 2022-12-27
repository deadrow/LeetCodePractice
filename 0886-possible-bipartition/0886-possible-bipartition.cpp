class Solution {
public:
    set<pair<int,int>> edges;
    
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
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.empty())
            return true;
        
        vector<vector<int>>adjList(n+1);
        
        for(auto it : dislikes)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        vector<int> color(n+1, -1);
        for(int v=1;v<=n;v++)
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