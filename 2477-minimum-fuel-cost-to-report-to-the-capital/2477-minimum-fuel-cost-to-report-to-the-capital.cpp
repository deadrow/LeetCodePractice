class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        
        vector<vector<int>> adjList(n+1);
        vector<int>indegree(n+1);
        vector<int>people(n+1, 1);
        
        for(auto it : roads)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        queue<int>bfs;
        for(int i=0;i<=n;i++)
        {
            if(indegree[i] == 1)
            {
                bfs.push(i);
            }
        }
        
        double ret = 0;
        while(!bfs.empty())
        {
            int u = bfs.front();
            bfs.pop();
            
            if(u == 0)
                continue;

            ret += ceil((double)people[u]/seats);
            
            for(auto v : adjList[u])
            {
                indegree[v]--;
                people[v] += people[u];
                if(indegree[v] == 1)
                {
                    bfs.push(v);
                }
            }
        }
        
        return ret;
    }
};