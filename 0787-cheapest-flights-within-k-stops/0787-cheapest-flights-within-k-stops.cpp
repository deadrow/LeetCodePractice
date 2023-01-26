class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjList(n);
        
        for(auto it : flights)
        {
            adjList[it[0]].push_back({it[1], it[2]});
        }
        
        queue<vector<int>>bfs;
        bfs.push({src, 0, 0});
        
        vector<bool>visited(n);
        
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!bfs.empty())
        {
            int u = bfs.front()[0];
            int distance = bfs.front()[1];
            int stops = bfs.front()[2];
            bfs.pop();

            if(stops > k)
                continue;
            
            for(auto it : adjList[u])
            {
                int v = it.first;
                int weight = it.second;

                if(dist[v] > distance+weight)
                {
                    dist[v] = distance+weight;
                    bfs.push({v, dist[v], stops+1});
                }
            }
        }
        
        
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};