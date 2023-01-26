class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjList(n);
        
        for(auto it : flights)
        {
            adjList[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int,int>>bfs;
        bfs.push({src,0});
        
        vector<bool>visited(n);
        
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        
        int stops=0;
        while(!bfs.empty() && stops<=k)
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                int u = bfs.front().first;
                int distance = bfs.front().second;
                bfs.pop();

                for(auto it : adjList[u])
                {
                    int v = it.first;
                    int weight = it.second;

                    if(dist[v] > (distance+weight))
                    {
                        dist[v] = distance+weight;
                        bfs.push({v, dist[v]});
                    }
                }
            }

            stops++;
        }
        
        
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};