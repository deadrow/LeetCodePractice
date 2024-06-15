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
    vector<vector<int>>paths;
    void traverse(TreeNode* root, int targetSum, vector<int>path){
        if(!root) return;
        if(!root->left and !root->right) {
            if(targetSum-root->val == 0){
                path.push_back(root->val);
                paths.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        traverse(root->left, targetSum-root->val, path);
        traverse(root->right, targetSum-root->val, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        traverse(root, targetSum, path);
        return paths;
    }
};