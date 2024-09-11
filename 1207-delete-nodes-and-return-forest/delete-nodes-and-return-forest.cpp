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
    vector<TreeNode*> ret;
    TreeNode* postorder(TreeNode*& root, unordered_set<int>& mp){
        if(!root) return nullptr;
        TreeNode* left = postorder(root->left, mp);
        TreeNode* right = postorder(root->right, mp);
        if(mp.count(root->val)){
            if(left)
                ret.push_back(left);
            if(right)
                ret.push_back(right);
            return root=nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>mp(to_delete.begin(), to_delete.end());
        TreeNode* remain = postorder(root, mp);
        if(remain)
            ret.push_back(remain);
        return ret;
    }
};