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
    int minDist = INT_MAX;
    int curNode = INT_MAX;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        minDist = min(abs(root->val-curNode), minDist);
        curNode = root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDist;
    }
};