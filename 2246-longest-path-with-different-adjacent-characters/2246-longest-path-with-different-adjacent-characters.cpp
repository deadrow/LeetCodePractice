class Solution {
public:
    int longestPathStr = 0;
    
    int dfs(vector<vector<int>>& child, string& s, int src)
    {
        int curMax = 0;
        priority_queue<int>childPaths;
        for(auto it : child[src])
        {
            auto longestPathFromChild = dfs(child, s, it);

            if(s[src] != s[it])
            {
                childPaths.push(longestPathFromChild);
            }
        }
        
        int firstMax = 0;
        if(!childPaths.empty())
        {
            firstMax = childPaths.top();
            curMax += firstMax;
            childPaths.pop();
        }
        
        if(!childPaths.empty())
            curMax += childPaths.top();
        
        longestPathStr = max(longestPathStr, curMax+1);
        return firstMax+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>child(s.size());
        
        for(int i=1;i<parent.size();i++)
        {
            child[parent[i]].push_back(i);
        }
        
        dfs(child, s, 0);
        return longestPathStr;
    }
};