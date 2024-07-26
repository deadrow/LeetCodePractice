class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        int minCount=n;
        int idx=0;
        for(int i=0;i<n;i++){
            queue<int>bfs;
            bfs.push(i);
            vector<int>dist(n, INT_MAX);
            dist[i]=0;
            while(!bfs.empty()){
                int u = bfs.front();
                bfs.pop();
                for(auto& [v, w] : adj[u]){
                    if(dist[u] + w < dist[v]){
                        dist[v] = dist[u]+w;
                        bfs.push(v);
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j and dist[j] <= distanceThreshold)
                    count++;
            }
            
            if(count <= minCount){
                minCount=count;
                idx = i;
            }
        }
        return idx;
    }
};