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
    void dfs(TreeNode* root, int level)
    {
        if(!root)
            return;
        
        // if vector size is reached. Allocate
        if(level == ret.size())
        {
            vector<int>temp;
            ret.push_back(temp);
            ret[level].push_back(root->val);
        }
        else
        {
            if(level & 1)
                ret[level].insert(ret[level].begin(), root->val);
            else
                ret[level].push_back(root->val);
        }
            
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};