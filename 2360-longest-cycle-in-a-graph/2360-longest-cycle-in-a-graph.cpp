class Solution {
public:
    vector<int>dist;
    vector<bool>visited;
    int longest=-1;
    
    void dfs(vector<vector<int>>& adjList, int src, int curDist)
    {
        if(dist[src] != -1)
        {
            longest = max(longest, curDist-dist[src]);
            return;
        }

        dist[src] = curDist;
        
        if(!visited[src])
        {
            visited[src] = true;
            for(int v : adjList[src])
            {
                dfs(adjList, v, curDist+1);
            }
        }

        dist[src] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        dist.resize(n, -1);
        visited.resize(n);

        vector<vector<int>>adjList(n);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i] != -1)
                adjList[i].push_back(edges[i]);
        }
            
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(adjList, i, 0);
        }
            
        return longest;
    }
};