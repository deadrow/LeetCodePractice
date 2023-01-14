/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int treeDiameter = 0;
    int dfs(Node* root)
    {
        priority_queue<int> paths;
        for(auto it : root->children)
        {
            int childPaths = dfs(it)+1;
            paths.push(childPaths);
        }
        
        int maxPath = 0;
        int curMax = 0;
        if(!paths.empty())
        {
            maxPath = paths.top();
            curMax += maxPath;
            paths.pop();
        }
        
        if(!paths.empty())
            curMax += paths.top();
        
        treeDiameter = max(treeDiameter, curMax);
        return maxPath;
    }
    
    int diameter(Node* root) {
        dfs(root);
        return treeDiameter;
    }
};