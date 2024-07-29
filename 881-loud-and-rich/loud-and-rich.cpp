class Solution {
public:
    vector<int>ret;
    int dfs(vector<vector<int>>& adj, int src, vector<int>& quiet){
        if(ret[src] != -1) return ret[src];
        ret[src]=src;
        for(int v : adj[src]){
            int minChildIdx = dfs(adj, v, quiet);
            if(quiet[minChildIdx] < quiet[ret[src]]){
                ret[src]=minChildIdx;
            }
        }
        return ret[src];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>adj(n);
        for(auto it : richer){
            adj[it[1]].push_back(it[0]);
        }
        ret.resize(n,-1);
        for(int i=0;i<n;i++){
            ret[i] = dfs(adj, i, quiet);
        }
        return ret;
    }
};