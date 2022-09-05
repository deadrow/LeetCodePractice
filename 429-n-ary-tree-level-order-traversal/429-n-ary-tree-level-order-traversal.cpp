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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        if(!root)
            return levels;
        
        queue<Node*> bfs;
        bfs.push(root);
        
        while(!bfs.empty())
        {
            int size = bfs.size();
            vector<int> cur_level;
            for(int i=0;i<size;i++)
            {
                Node* node = bfs.front();
                bfs.pop();
                cur_level.push_back(node->val);
                for(auto it : node->children)
                {
                    bfs.push(it);
                }
            }
            
            levels.push_back(cur_level);
        }
        
        return levels;
    }
};