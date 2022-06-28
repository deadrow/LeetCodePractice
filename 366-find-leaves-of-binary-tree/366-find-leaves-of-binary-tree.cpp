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
    TreeNode* postorder(TreeNode* root, vector<int>& cur)
    {
        if(!root)
            return nullptr;
        
        TreeNode* left = postorder(root->left, cur);
        TreeNode* right = postorder(root->right, cur);
        if(!root->left && !root->right)
        {
            cur.push_back(root->val);
            return nullptr;
        }
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        while(root)
        {
            vector<int> cur;
            root = postorder(root, cur);
            ret.push_back(cur);
        }
        
        return ret;
    }
};