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
    vector<vector<int>> res;
    map<int, multiset<pair<int,int>>> group;
    void helper(TreeNode* root, int cur, int level)
    {
        if(!root)
            return;
        
        group[cur].insert({level,root->val});
        helper(root->left, cur-1, level+1);
        helper(root->right, cur+1, level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        helper(root, 0, 0);
        
        for(auto it : group)
        {
            vector<int> temp;
            for(auto it1 : it.second)
                temp.push_back(it1.second);
            
            res.push_back(temp);
        }

        return res;
    }
};