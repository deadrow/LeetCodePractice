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
    int cur_index=0;
    unordered_map<int, int> cache;
    TreeNode* buildTreeHelper(TreeNode* root, vector<int>& preorder, int left, int right)
    {
        if(left > right)
            return nullptr;
        
        root = new TreeNode(preorder[cur_index]);
        
        int inorder_index = cache[preorder[cur_index++]];
        root->left = buildTreeHelper(root->left, preorder, left, inorder_index-1);
        root->right = buildTreeHelper(root->right, preorder, inorder_index+1, right);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            cache.insert({inorder[i],i});
        }
        
        TreeNode* root = nullptr;
        return buildTreeHelper(root, preorder, 0, inorder.size()-1);
    }
};