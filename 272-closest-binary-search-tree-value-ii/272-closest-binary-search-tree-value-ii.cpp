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
    priority_queue<pair<double, int>>pq;
    void inorder(TreeNode* root, double target, int k)
    {
        if(!root)
            return;
        
        inorder(root->left, target, k);
        
        pq.push({abs(root->val-target), root->val});
                
        if(pq.size() > k)
            pq.pop();
        
        inorder(root->right, target, k);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        
        inorder(root, target, k);
        
        while(!pq.empty())
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        
        return ret;
    }
};