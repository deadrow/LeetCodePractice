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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        queue<TreeNode*>bfs;
        bfs.push(root);
        
        while(!bfs.empty())
        {
            long total = 0;
            int count = 0;
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = bfs.front();
                bfs.pop();
                
                total += cur->val;
                count++;
                
                if(cur->left)
                    bfs.push(cur->left);
                
                if(cur->right)
                    bfs.push(cur->right);
            }
            
            res.push_back(total/(double)count);
        }
        
        return res;
    }
};