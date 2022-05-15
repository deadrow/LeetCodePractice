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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        int sum = 0;
        while(!bfs.empty())
        {
            int size = bfs.size();
            
            int curSum = 0;
            for(int i=0;i< size;i++)
            {
                TreeNode* node = bfs.front();
                bfs.pop();
                
                curSum += node->val;
                
                if(node->left)
                    bfs.push(node->left);
                
                if(node->right)
                    bfs.push(node->right);
            }
            
            sum = curSum;
        }
        
        return sum;
    }
};