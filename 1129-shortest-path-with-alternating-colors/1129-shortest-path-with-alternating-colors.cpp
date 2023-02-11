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
        
        vector<vector<int>>dist(n, vector<int>(2, INT_MAX));
        dist[0][0] = dist[0][1] = 0;
        
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
                if(color != prevColor && dist[v][color] > steps+1)
                {
                    // visited[v][color] = true;
                    bfs.push({v, steps+1, color});
                    dist[v][color] = steps+1;
                }
            }
        }
        
        vector<int>ret(n);
        
        for(int i=0;i<n;i++)
        {
            ret[i] = min(dist[i][0], dist[i][1]);
            if(ret[i] == INT_MAX)
                ret[i] = -1;
        }
        return ret;
    }
};