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
    queue<TreeNode*> bfs;
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        
        if(!root)
            return {};
        
        bfs.push(root);
        
        while(!bfs.empty())
        {
            int size = bfs.size();
            
            vector<int> cur_set;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = bfs.front();
                bfs.pop();
                
                if(cur->left)
                    bfs.push(cur->left);
                
                if(cur->right)
                    bfs.push(cur->right);
                
                cur_set.push_back(cur->val);
            }
            
            res.push_back(cur_set);
        }
        
        return res;
            
    }
};