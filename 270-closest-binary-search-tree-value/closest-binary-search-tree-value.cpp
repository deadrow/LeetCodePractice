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
    void dfs(TreeNode* root, double target)
    {
        if(!root)
            return;
        
        // If the diff is same, select the lowest node
        if(abs(target-root->val) == min_diff) {
            min_node = min(root->val,min_node);
        } else if(abs(target-root->val) < min_diff) {
            min_diff = abs(target-root->val);
            min_node = root->val;
        }
        
        if(target < (double)root->val)
            dfs(root->left, target);
        else
            dfs(root->right, target);
    }
    
    int closestValue(TreeNode* root, double target)
    {
        dfs(root, target);
        return min_node;
    }
};