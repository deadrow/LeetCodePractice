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
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>>pq;
    void inorder(TreeNode* root, double target)
    {
        if(!root)
            return;
        
        inorder(root->left, target);
        pq.push({abs(root->val-target), root->val});
        inorder(root->right, target);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        
        inorder(root, target);
        
        while(!pq.empty() && k--)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        
        return ret;
    }
};