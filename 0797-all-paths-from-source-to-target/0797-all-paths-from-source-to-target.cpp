class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        
        queue<vector<int>> bfs;
        bfs.push({0});
        
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                auto top = bfs.front();
                bfs.pop();
                
                if(top.back() == n-1)
                {
                    result.push_back(top);
                    continue;
                }
                
                for(auto it : graph[top.back()])
                {
                    vector<int> cur(top);
                    cur.push_back(it);
                    bfs.push(cur);
                }
            }
        }
        
        return result;
    }
};