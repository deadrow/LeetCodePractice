class Solution {
public:
    bool intersects(const vector<int>& a, const vector<int>& b)
    {
        double r1 = a[2];
        long d = (pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
        return r1*r1 >= d;
    }

    int dfs(vector<vector<int>>& adjList, int src, vector<bool>& visited)
    {
        visited[src] = true;
        int count = 1;
        for(auto v : adjList[src])
        {
            if(!visited[v])
                count += dfs(adjList, v, visited);
        }

        // visited[src] = false;
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adjList(n);

        for(int i=0;i<bombs.size();i++)
        {
            for(int j=0;j<bombs.size();j++)
            {
                if(i != j && intersects(bombs[i], bombs[j]))
                    adjList[i].push_back(j);
            }
        }

        int maxExplosions = 0;
        for(int i=0;i<bombs.size();i++)
        {
            vector<bool> visited(n);
            int count = dfs(adjList, i, visited);
            maxExplosions = max(maxExplosions, count);
        }

        return maxExplosions;
    }
};