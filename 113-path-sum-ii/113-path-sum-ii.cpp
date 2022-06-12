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
    vector<vector<int>> ret;
    
    void traverse(TreeNode* root, vector<int> curSet, int targetSum)
    {
        if(!root)
        {
            // if(targetSum == 0)
            //     ret.push_back(curSet);
            return;
        }
        
        curSet.push_back(root->val);
        
        if(!root->left && !root->right)
        {
            if(targetSum-root->val == 0)
                ret.push_back(curSet);
                
        }
        traverse(root->left, curSet, targetSum-root->val);
        traverse(root->right, curSet, targetSum-root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curSet;
        traverse(root, curSet, targetSum);
        return ret;
    }
};