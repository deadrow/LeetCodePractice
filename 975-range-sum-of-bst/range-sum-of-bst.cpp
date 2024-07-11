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
    void traverse(TreeNode* root, int low, int high){
        if(!root) return;
        if(root->val >= low and root->val <= high){
            sum += root->val;
        }
        if(low < root->val)
            traverse(root->left, low, high);

        if(high > root->val)
            traverse(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root, low, high);
        return sum;
    }
};