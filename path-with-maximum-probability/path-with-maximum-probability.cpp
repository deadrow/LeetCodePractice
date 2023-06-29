class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> ajdList(n);

        for(int i=0;i<edges.size();i++)
        {
            ajdList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            ajdList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        queue<pair<int, double>>bfs;
        bfs.push({start, 1.0});
        
        vector<bool>visited(n);
        
        vector<double>dist(n, 0.0);
        dist[start] = 1.0;
        
        while(!bfs.empty())
        {
            int u = bfs.front().first;
            double distance = bfs.front().second;
            bfs.pop();

            for(auto it : ajdList[u])
            {
                int v = it.first;
                double weight = it.second;

                if(dist[v] < distance*weight)
                {
                    dist[v] = distance*weight;
                    bfs.push({v, dist[v]});
                }
            }
        }

        return dist[end];
    }
};