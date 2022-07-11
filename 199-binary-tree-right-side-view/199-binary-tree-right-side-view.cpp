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
    vector<int> res;
    vector<vector<int>> levels;
    void dfs(TreeNode* root, int height)
    {
        if(!root)
            return;
  
        if(levels.size() == height)
        {
            levels.push_back({});
            res.push_back(-1);
        }
         
        dfs(root->right, height+1);
        dfs(root->left, height+1);
   
        levels[height].push_back(root->val);
        
        if(res[height] == -1)
            res[height] = levels[height].front();
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;
        
        dfs(root, 0);

        return res;
    }
};