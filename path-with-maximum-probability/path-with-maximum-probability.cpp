class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> ajdList(n);

        for(int i=0;i<edges.size();i++)
        {
            ajdList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            ajdList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start});
        
        vector<double>dist(n, 0.0);
        dist[start] = 1.0;
        
        while(!pq.empty())
        {
            double distance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(u == end)
                return distance;

            for(auto it : ajdList[u])
            {
                int v = it.first;
                double weight = it.second;

                if(dist[v] < distance*weight)
                {
                    dist[v] = distance*weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return 0.0;
    }
};