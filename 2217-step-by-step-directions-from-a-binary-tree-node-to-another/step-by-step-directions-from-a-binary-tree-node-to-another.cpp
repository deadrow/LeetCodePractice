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
    TreeNode* lca(TreeNode* root, int startValue, int destValue){
        if(!root) return nullptr;
        if(root->val == startValue or root->val == destValue) return root;
        TreeNode* left = lca(root->left, startValue, destValue);
        TreeNode* right = lca(root->right, startValue, destValue);
        if(left and right) return root;
        return left ? left : right;
    }
    bool path(TreeNode* root, int node, string& curPath){
        if(!root) return false;
        if(root->val == node)
            return true;
        curPath += "L";
        if(path(root->left, node, curPath)) return true;
        curPath.pop_back();
        curPath += "R";
        if(path(root->right, node, curPath)) return true;
        curPath.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lca(root, startValue, destValue);
        string curPathStart, curPathDest;
        path(lcaNode, startValue, curPathStart);
        path(lcaNode, destValue, curPathDest);
        return string(curPathStart.size(), 'U') + curPathDest;
    }
};