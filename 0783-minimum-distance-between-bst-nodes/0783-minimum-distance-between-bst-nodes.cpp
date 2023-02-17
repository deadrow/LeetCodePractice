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
    vector<int>nums;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        
        int diff = INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            diff = min(diff, abs(nums[i-1]-nums[i]));
        }
        
        return diff;
    }
};