class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times)
            adj[it[0]].push_back({it[1], it[2]});
        vector<int>dist(n+1, INT_MAX);
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(k);
        dist[k]=0;
        while(!pq.empty()){
            int u = pq.top(); pq.pop();
            for(auto [v, w] : adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({v});
                }
            }
        }

        int maxTime=0;
        for(int i=1;i<=n;i++){
            maxTime = max(dist[i], maxTime);
        }
        return maxTime == INT_MAX? -1 : maxTime;
    }
};