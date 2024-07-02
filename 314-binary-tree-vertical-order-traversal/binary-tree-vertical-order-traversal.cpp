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
    vector<vector<int>> verticalOrder1(TreeNode* root) {
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

    // bfs solution
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<pair<TreeNode*,int>>bfs;
        bfs.push({root, 0});

        map<int, vector<int>>mp;

        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
            mp[cur.second].push_back(cur.first->val);

            if(cur.first->left){
                bfs.push({cur.first->left, cur.second-1});
            }
            if(cur.first->right){
                bfs.push({cur.first->right, cur.second+1});
            }
        }

        
        for(auto it : mp){
            ret.push_back(it.second);
        }
        return ret;
    }
};