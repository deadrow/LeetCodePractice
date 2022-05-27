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
    int solve(TreeNode* root, int& res)
    {
        if(!root)
            return 0;
        
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        
        int ansFromRoot = max(max(left, right) + root->val, root->val);
        int ansWithoutRoot = max(ansFromRoot, left+right+root->val);
        res = max(res, ansWithoutRoot);
        return ansFromRoot;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};