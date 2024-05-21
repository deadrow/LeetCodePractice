/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int found = 0;
    bool foundQ = false;
    TreeNode* LCAUtil(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        TreeNode* left = LCAUtil(root->left, p, q);
        TreeNode* right = LCAUtil(root->right, p, q);

        // Move this after recursion otherwise it would return early
        if(root == p || root == q) {
            found++;
            return root;
        }

        if(left && right) return root;
        return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = LCAUtil(root, p, q);
        return (found == 2) ? ret : nullptr;
    }
};