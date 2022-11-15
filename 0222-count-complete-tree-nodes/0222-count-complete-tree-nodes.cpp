/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*>bfs;
        bfs.push(root);
        
        int nodes = 0;
        while(!bfs.empty())
        {
            int size = bfs.size();
            nodes += size;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = bfs.front();
                bfs.pop();
                
                if(cur->left)
                    bfs.push(cur->left);
                
                if(cur->right)
                    bfs.push(cur->right);
            }
        }
        
        return nodes;
    }
};