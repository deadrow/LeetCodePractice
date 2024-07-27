class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>>adj(n+1);
        vector<int>indeg(n+1);
        for(auto it : relations){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }

        queue<int>bfs;
        int courses=0;
        for(int i=1;i<=n;i++){
            if(indeg[i] == 0){
                courses++;
                bfs.push(i);
            }
        }
            
        int sems=0;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i=0;i<size;i++){
                int u = bfs.front(); bfs.pop();
                for(auto v : adj[u]){
                    indeg[v]--;
                    if(indeg[v] == 0){
                        courses++;
                        bfs.push(v);
                    }
                }
            }
            sems++;
        }
        return courses == n ? sems : -1;
    }
};