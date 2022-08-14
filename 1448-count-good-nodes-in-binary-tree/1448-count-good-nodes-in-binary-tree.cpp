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
    int dfs(TreeNode* root, int curMax)
    {
        if(!root)
            return 0;
        
        int cur = 0;
        if(root->val >= curMax)
            cur += 1;
        
        return cur + dfs(root->left, max(root->val, curMax)) + dfs(root->right, max(root->val, curMax));
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        return dfs(root, INT_MIN);
    }
};