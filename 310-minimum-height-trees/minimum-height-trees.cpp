class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return {0};
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
            indeg[it[1]]++;
        }

        queue<int>bfs;
        for(int i=0;i<n;i++){
            if(indeg[i] == 1){
                bfs.push(i);
            }
        }
            
        vector<int>ret;
        int nodesLeft=n;
        while(!bfs.empty()){
            int size = bfs.size();
            nodesLeft -= size;
            
            for(int i=0;i<size;i++){
                int u = bfs.front(); bfs.pop();
                if(nodesLeft == 0) ret.push_back(u);
                for(auto v : adj[u]){
                    indeg[v]--;
                    if(indeg[v] == 1){
                        bfs.push(v);
                    }
                }
            }
        }
        return ret;
    }
};