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
    map<int, vector<int>>mp;
    void traverse(TreeNode* root, int height){
        if(!root) return;
        mp[height].push_back(root->val);
        traverse(root->left, height+1);
        traverse(root->right, height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        traverse(root, 0);
        vector<int> ret;
        for(auto it : mp){
            ret.push_back(it.second.back());
        }
        return ret;
    }
};