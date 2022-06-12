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
    vector<int> ret;
    void traverse(TreeNode* root, int cur)
    {
        if(!root)
            return;

        cur = cur*10 + root->val;
        
        if(!root->left && !root->right)
            ret.push_back(cur);
        
        traverse(root->left, cur);
        traverse(root->right, cur);
    }
    
    int sumNumbers(TreeNode* root) {
        traverse(root, 0);
        int ans = 0;
        for(auto it : ret)
            ans += it;
        
        return ans;
    }
};