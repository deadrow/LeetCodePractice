class Solution {
public:
    void bfs(vector<vector<int>>& adjList, vector<int>& dist, int start)
    {
        dist[start] = 0;
        
        queue<int> bfs;
        bfs.push(start);
        
        while(!bfs.empty())
        {
            int u = bfs.front();
            bfs.pop();
            
            for(auto it : adjList[u])
            {
                int v = it;
                
                if(dist[v] > dist[u]+1)
                {
                    dist[v] = dist[u]+1;
                    bfs.push(v);
                }
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>>adjList(n);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i] != -1)
                adjList[i].push_back(edges[i]);
        }
        
        vector<int>dist1(n, INT_MAX);
        vector<int>dist2(n, INT_MAX);
        
        bfs(adjList, dist1, node1);
        bfs(adjList, dist2, node2);
        
        int curMin = INT_MAX;
        
        int index = -1;
        for(int i=0;i<n;i++)
        {
            if(dist1[i] != INT_MAX && dist2[i] != INT_MAX)
            {
                if(max(dist1[i],dist2[i]) < curMin)
                {
                    index = i;
                    curMin = max(dist1[i],dist2[i]);
                }
            }
        }
        
        return index;
    }
};