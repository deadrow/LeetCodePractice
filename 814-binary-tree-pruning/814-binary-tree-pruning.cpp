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
    pair<TreeNode*, bool> helper(TreeNode* root)
    {
        if(!root)
            return {nullptr, false};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        bool hasOne = false;
        if(left.first)
        {
            if(left.first->val == 1 || left.second)
            {
                hasOne = true;
            }
            else
                root->left = nullptr;
        }
        
        if(right.first)
        {
            if(right.first->val == 1 || right.second)
            {
                hasOne = true;
            }
            else
                root->right = nullptr;
        }
        
        if(!hasOne)
        {
            // check if root has one
            if(root->val == 1)
                hasOne = true;
        }
        
        return {root, hasOne};
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* ret = helper(root).first;
        if(ret)
        {
            if(ret->val == 0 && !ret->left && !ret->right)
                ret = nullptr;
        }
        
        return ret;
    }
};