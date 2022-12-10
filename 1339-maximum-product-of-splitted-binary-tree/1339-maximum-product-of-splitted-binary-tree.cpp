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
    int MOD = 1000000007;
    long maxProd = 0;
    int totalSum = 0;

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int curSum = left+root->val+right;
        maxProd = max(maxProd, (long)curSum*(totalSum-curSum));
        return curSum;
    }
    
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        dfs(root);
        return maxProd% MOD;
    }
};