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
    vector<int>leavesFirst;
    vector<int>leavesSecond;
    
    void inorder(TreeNode* root, vector<int>& leaves)
    {
        if(root)
        {
            inorder(root->left, leaves);
            if(!root->left && !root->right)
                leaves.push_back(root->val);
            inorder(root->right, leaves);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder(root1, leavesFirst);
        inorder(root2, leavesSecond);
        return leavesFirst == leavesSecond;
    }
};