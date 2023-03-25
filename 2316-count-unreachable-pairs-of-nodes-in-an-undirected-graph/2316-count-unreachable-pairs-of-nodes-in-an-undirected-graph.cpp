class Solution {
public:
    vector<int>visited;
    int dfs(vector<vector<int>>& adjList, int src)
    {
        visited[src] = true;
        
        int count  = 1;
        for(auto it : adjList[src])
        {
            if(!visited[it])
            {
                count += dfs(adjList, it);
            }
        }
        
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        
        if(edges.empty())
            return (long)n*(n-1)/2;
        
        for(auto it : edges)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        visited.resize(n);
        
        vector<int>clusters;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                clusters.push_back(dfs(adjList, i));
        }
        
        long res = 0;
        int total = 0;
        for(int i = 0;i<clusters.size();i++){
            res+=(long)((long)clusters[i]*(long)(n-total-clusters[i]));
            total+=clusters[i];
        }
        return res;
    }
};