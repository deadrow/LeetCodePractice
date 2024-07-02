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
    // dfs solution
    map<int,map<int,vector<int>>>dict;
    void traverse(TreeNode* root, int row, int col){
        if(!root) return;
        dict[col][row].push_back(root->val);
        traverse(root->left, row+1, col-1);
        traverse(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        traverse(root, 0,0);
        vector<vector<int>> ret;
        for(auto col : dict){
            vector<int> cur;
            for(auto row : col.second){
                for(auto it : row.second)
                    cur.push_back(it);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};