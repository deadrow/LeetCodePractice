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
    struct Data{
        int maxNode;
        int minNode;
        int nodes;
    };

    int maxNodes = 0;
    Data traverse(TreeNode* root){
        if(!root) return {INT_MIN, INT_MAX, 0};
        Data left = traverse(root->left);
        Data right = traverse(root->right);
        if(root->val > left.maxNode and root->val < right.minNode){
            cout << "here with :" << root->val << ",";
            return {max(right.maxNode, root->val), min(left.minNode, root->val), left.nodes+right.nodes+1};
        }
        return {INT_MAX, INT_MIN, max(left.nodes, right.nodes)};
    }

    int largestBSTSubtree(TreeNode* root) {
        return traverse(root).nodes;
    }
};