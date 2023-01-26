class Solution {
public:
    int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int k) {
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
    
    // Bellman ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance from source to all other nodes by using n edges
        // Bellman ford calculates min distance with 1,2,3,4,.... n edges
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Run only K+1 times since we want shortest distance in K hops.
        for (int i = 0; i <= k; i++) 
        {
            vector<int>temp(dist);
            for (auto& flight : flights) 
            {
                if(dist[flight[0]] != INT_MAX)
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
            }
            
            dist = temp;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};