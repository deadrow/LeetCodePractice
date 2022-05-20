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
            
            vector<int> cur_res;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = bfs.front();
                bfs.pop();
                
                cur_res.push_back(cur->val);
                
                if(cur->left)
                    bfs.push(cur->left);
                
                if(cur->right)
                    bfs.push(cur->right);
            }
            
            if(direction)
            {
                reverse(cur_res.begin(), cur_res.end());
            }
            
            direction = !direction;
            res.push_back(cur_res);
        }
        
        return res;
    }
};