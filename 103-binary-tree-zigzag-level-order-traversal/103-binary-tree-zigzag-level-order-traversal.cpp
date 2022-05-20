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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        queue<TreeNode*> bfs;
        
        bfs.push(root);
        
        bool direction = false; // 0 means left to right 1 means right to left
        while(!bfs.empty())
        {
            int size = bfs.size();
            
            list<int> cur_res;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = bfs.front();
                bfs.pop();
                
                if(cur->left)
                    bfs.push(cur->left);
                
                if(cur->right)
                    bfs.push(cur->right);
                
                if(direction)
                {
                    cur_res.push_front(cur->val);
                }
                else
                    cur_res.push_back(cur->val);
            }
            
            direction = !direction;
            
            vector<int> cur_arr(cur_res.begin(), cur_res.end());
            res.push_back(cur_arr);
        }
        
        return res;
    }
};