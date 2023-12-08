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
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
        
        string val = to_string(root->val);
        string left = tree2str(root->left);
        string right = tree2str(root->right);

        if(left.empty() and right.empty())
            return val;

        val += "(" + left + ")";

        if(!right.empty())
            val += "(" + right + ")";

        return val;
    }
};