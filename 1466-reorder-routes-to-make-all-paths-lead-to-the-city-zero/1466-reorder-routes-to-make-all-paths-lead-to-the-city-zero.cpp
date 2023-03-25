class Solution {
public:
    int changed = 0;
    vector<bool>visited;
    set<pair<int,int>>actual;
    
    void dfs(vector<vector<int>>&adjList , int src)
    {
        visited[src] = true;
        for(auto it : adjList[src])
        {
            if(!visited[it])
            {
                if(actual.find({src,it}) != actual.end())
                    changed++;
                
                dfs(adjList, it);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjList(n);
        for(auto it : connections)
        {
            actual.insert({it[0], it[1]});
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        visited.resize(n);
        dfs(adjList, 0);
        
        return changed;
    }
};