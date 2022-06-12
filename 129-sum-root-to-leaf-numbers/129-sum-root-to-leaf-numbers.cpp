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
    vector<string> ret;
    void traverse(TreeNode* root, string cur)
    {
        if(!root)
            return;

        cur += to_string(root->val);
        
        if(!root->left && !root->right)
            ret.push_back(cur);
        
        traverse(root->left, cur);
        traverse(root->right, cur);
        cur.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        string cur;
        traverse(root, cur);
        int ans = 0;
        for(auto it : ret)
            ans += stoi(it);
        
        return ans;
    }
};