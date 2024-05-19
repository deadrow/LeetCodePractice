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
    double min_diff = std::numeric_limits<double>::max();
    int min_node = INT_MAX;
    void helper(TreeNode* root, double target)
    {
        if(!root)
            return;
        
        if(abs(target-root->val) == min_diff)
        {
            min_diff = abs(target-root->val);
            min_node = min(root->val,min_node);
        }

        if(abs(target-root->val) < min_diff)
        {
            min_diff = abs(target-root->val);
            min_node = root->val;
        }
        
        if(target < (double)root->val)
        {
            helper(root->left, target);
        }
        else
        {
            helper(root->right, target);
        }
    }
    
    int closestValue(TreeNode* root, double target)
    {
        helper(root, target);
        
        return min_node;
    }
};