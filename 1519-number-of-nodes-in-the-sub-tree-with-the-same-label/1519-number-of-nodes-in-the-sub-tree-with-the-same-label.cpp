class Solution {
public:
    vector<int>result;
    vector<bool>visited;
    vector<int> dfs(vector<vector<int>>& adjList, int src, string& labels)
    {
        vector<int> cur(26);
        visited[src] = true;
        for(auto it : adjList[src])
        {
            if(!visited[it])
            {
                vector<int> child = dfs(adjList, it, labels);
                
                for(int i=0;i<26;i++)
                    cur[i] += child[i];
                
                cur[labels[it]-'a']++;
            }
        }
        
        result[src] += cur[labels[src]-'a']+1;
    
        return cur;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        result.resize(n);
        visited.resize(n);
        
        vector<vector<int>> adjList(n);
        for(auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
            
        dfs(adjList, 0, labels);
        return result;
    }
};