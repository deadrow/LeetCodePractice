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
        
        if(ret.empty() || height > (ret.size()-1))
            ret.push_back(vector<int>());
        
        ret[height].push_back(root->val);
        
        traverse(root->left, height+1);
        traverse(root->right, height+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        traverse(root, 0);
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};