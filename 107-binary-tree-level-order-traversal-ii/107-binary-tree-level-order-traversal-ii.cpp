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
    vector<vector<int>> ret;
    map<int,vector<int>, greater<>> map;
    void traverse(TreeNode* root, int height)
    {
        if(!root)
            return;
        
        traverse(root->left, height+1);
        traverse(root->right, height+1);
        
        map[height].push_back(root->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        traverse(root, 0);
        
        for(auto it : map)
            ret.push_back(it.second);
        
        return ret;
    }
};