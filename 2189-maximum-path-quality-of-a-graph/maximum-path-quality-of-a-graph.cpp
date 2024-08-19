class Solution {
public:
    int maxQual=0;
    void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& values, int qual, int maxTime, int curTime, int src, vector<int>&visited){
        if(curTime > maxTime)return;
        if(visited[src] == 0)
            qual += values[src];
        if(src == 0)
            maxQual = max(qual, maxQual);

        visited[src]++;
        for(auto& [v, w] : adj[src]){
            dfs(adj, values, qual, maxTime, curTime+w, v, visited);
        }
        visited[src]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<pair<int,int>>>adj(1001);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int>visited(1001);
        dfs(adj, values, 0, maxTime, 0, 0, visited);
        return maxQual;
    }
};