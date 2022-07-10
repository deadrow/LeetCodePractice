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
    int ans = 0;
    enum
    {
        kNotNeeded=0,
        kNoCamera,
        kHasCamera
    };
    
    int dfs(TreeNode* root)
    {
        if(!root)
            return kNotNeeded;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
    
        if(left == kNoCamera || right == kNoCamera)
        {
            ans++;
            return kHasCamera;
        }
        else if(left == kHasCamera || right == kHasCamera)
            return kNotNeeded;
        else return kNoCamera;
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == kNoCamera) ans++;
        return ans;
    }
};