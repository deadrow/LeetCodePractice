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
    unordered_map<string, int>dict;
    vector<TreeNode*> ret;
    string dfs(TreeNode* root)
    {
        if(!root)
            return "";
        
        string left = dfs(root->left);
        string right = dfs(root->right);
        
        string key = "(" + left + ")" + to_string(root->val) + "(" + right + ")";
        dict[key]++;
        if(dict[key] == 2)
            ret.push_back(root);

        return key;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);

        return ret;
    }
};