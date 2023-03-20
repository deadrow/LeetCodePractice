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
    unordered_map<string, pair<TreeNode*, int>>dict;
    
    string dfs(TreeNode* root)
    {
        if(!root)
            return "";
        
        string left = dfs(root->left);
        string right = dfs(root->right);
        
        string key = "(" + left + ")" + to_string(root->val) + "(" + right + ")";
        if(dict.find(key) == dict.end())
            dict[key] = {root, 1};
        else
        {
            dict[key] = {root, dict[key].second+1};
        }
        
        return key;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        
        vector<TreeNode*> ret;
        
        for(auto it : dict)
        {
            if(it.second.second > 1)
                ret.push_back(it.second.first);
        }
        return ret;
    }
};