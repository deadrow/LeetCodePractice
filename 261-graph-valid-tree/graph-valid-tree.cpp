class Solution {
public:
    bool cycle(vector<vector<int>>& adj, int src, int p, unordered_set<int>& visited){
        if(visited.count(src)) return true;
        visited.insert(src);
        for(auto v : adj[src]){
            if(v!=p and cycle(adj, v, src, visited)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_set<int> visited;
        return !cycle(adj, 0, -1, visited) and visited.size() == n;
    }
};