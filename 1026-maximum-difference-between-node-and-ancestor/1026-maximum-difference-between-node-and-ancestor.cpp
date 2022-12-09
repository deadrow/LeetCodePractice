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
    int maxDiff = INT_MIN;
    pair<int,int> dfs(TreeNode* root)
    {
        if(!root)
            return {INT_MAX,INT_MIN};
        
        if(!root->left && !root->right)
            return {root->val, root->val};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        int maxVal = max({left.second, right.second, root->val});
        int minVal = min({left.first, right.first, root->val});
        
        int curMaxDiff = max(abs(root->val-maxVal), abs(root->val-minVal));
        maxDiff = max(maxDiff, curMaxDiff);
        
        return {minVal, maxVal};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return maxDiff;
    }
};