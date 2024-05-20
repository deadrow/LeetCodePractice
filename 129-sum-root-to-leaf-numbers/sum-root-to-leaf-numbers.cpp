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
            cout << cur + to_string(root->val) << endl;
            sum += stoi(cur + to_string(root->val));
            return;
        }
        traverse(root->left, cur + to_string(root->val));
        traverse(root->right, cur + to_string(root->val));
    }
    int sumNumbers(TreeNode* root) {
        traverse(root, "");
        return sum;
    }
};