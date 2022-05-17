/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& res)
    {
        if(!original)
            return;
        
        inorder(original->left, cloned->left, target, res);
        
        if(original == target)
        {
            res = cloned;
            return;
        }
           
        inorder(original->right, cloned->right, target, res);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res = nullptr;
        inorder(original, cloned, target, res);
        return res;
    }
};