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
    int maxSum = INT_MIN;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;
        
        maxSum = max(maxSum, left+right+root->val);
        return max(left+root->val, right+root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};