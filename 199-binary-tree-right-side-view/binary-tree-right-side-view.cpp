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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ret;
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i=0;i<size;i++){
                TreeNode* cur = bfs.front(); bfs.pop();
                if(i==0) ret.push_back(cur->val);
                if(cur->right)
                    bfs.push(cur->right);
                if(cur->left)
                    bfs.push(cur->left);
            }
        }
        return ret;
    }
};