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
    int sum = 0;
    void traverse(TreeNode* root, string cur) {
        if(!root) return;
        if(!root->left and !root->right) {
            char digit =  root->val + '0';
            sum += stoi(cur + digit);
            return;
        }
        char digit =  root->val + '0';
        traverse(root->left, cur + digit);
        traverse(root->right, cur + digit);
    }
    int sumNumbers(TreeNode* root) {
        traverse(root, "");
        return sum;
    }
};