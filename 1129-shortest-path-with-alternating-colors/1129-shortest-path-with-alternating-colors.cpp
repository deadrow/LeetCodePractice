class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>>adjList(n);
        
        for(auto it : redEdges)
        {
            adjList[it[0]].push_back({it[1], 0});
        }
        
        for(auto it : blueEdges)
        {
            adjList[it[0]].push_back({it[1], 1});
        }
        
        vector<int>dist(n,-1);
        dist[0] = 0;
        
        vector<vector<bool>>visited(n, vector<bool>(2));
        visited[0][0] = visited[0][1] = true;
        
        queue<vector<int>>bfs;
        bfs.push({0,0,-1}); // initial color with -1
        
        while(!bfs.empty())
        {
            auto cur = bfs.front();
            bfs.pop();
            
            int u = cur[0];
            int steps = cur[1];
            int prevColor = cur[2];
            
            for(auto [v, color] : adjList[u])
            {
                if(!visited[v][color] && color != prevColor)
                {
                    visited[v][color] = true;
                    bfs.push({v, steps+1, color});
                    
                    // if dist not filled, fill it
                    if(dist[v] == -1)
                        dist[v] = steps+1;
                }
            }
        }
        return dist;
    }
};