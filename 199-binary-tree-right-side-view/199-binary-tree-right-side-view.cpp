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
    
    void bfs(TreeNode* root)
    {
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = bfs.front();
                bfs.pop();
                
                if(i == size-1)
                    res.push_back(node->val);
                
                if(node->left)
                    bfs.push(node->left);
                
                if(node->right)
                    bfs.push(node->right);
            }
        }
    }
    
    void dfs(TreeNode* root, int height)
    {
        if(!root)
            return;
  
        if(res.size() == height)
        {
            res.push_back(root->val);
        }
         
        dfs(root->right, height+1);
        dfs(root->left, height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;
        
        dfs(root, 0);

        return res;
    }
};