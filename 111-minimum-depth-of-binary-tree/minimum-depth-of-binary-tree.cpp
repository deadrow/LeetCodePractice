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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);

        int height = 0;
        if(leftHeight and rightHeight)
            height = min(leftHeight, rightHeight)+1;
        else
            height = 1 + (leftHeight ? leftHeight : rightHeight);
        
        return height;
    }
};