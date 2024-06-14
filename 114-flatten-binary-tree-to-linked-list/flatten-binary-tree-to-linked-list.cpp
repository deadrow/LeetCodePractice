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
    vector<TreeNode*>tree;
    void preorder(TreeNode* root){
        if(!root) return;
        tree.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        preorder(root);
        TreeNode* dummy = new TreeNode(0);
        TreeNode* cur = dummy;
        for(auto& it : tree){
            cur->right = it;
            cur->left = nullptr;
            cur = cur->right;
        }
        root = nullptr;
        root = dummy->right;
    }
};