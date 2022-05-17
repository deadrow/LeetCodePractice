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
    TreeNode* clonedNode = nullptr;
    
    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if(!original || !cloned)
            return;
        
        if(original == target)
        {
            clonedNode = cloned;
            return;
        }
            
        helper(original->left, cloned->left, target);
        helper(original->right, cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        helper(original, cloned, target);
        return clonedNode;
    }
};