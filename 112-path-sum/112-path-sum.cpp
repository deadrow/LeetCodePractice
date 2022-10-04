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
    int found = false;
    void DFS(TreeNode* root, int targetSum) {
        
        if(!root)
            return;
        
        if(!root->left && !root->right)
        {
            if(targetSum - root->val == 0)
            {
                found = true;
                return;
            }
        }

        DFS(root->left, targetSum - root->val);
        DFS(root->right, targetSum - root->val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        DFS(root, targetSum);
        return found;
    }
};