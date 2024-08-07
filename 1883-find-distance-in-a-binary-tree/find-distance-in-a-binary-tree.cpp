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
    int distance(TreeNode* root, int node, int dist=0){
        if(!root) return -1;
        if(root->val == node) return dist;
        int left = distance(root->left, node, dist+1);
        if(left != -1) return left;
        return distance(root->right, node, dist+1);
    }
    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root) return nullptr;
        if(root->val == p or root->val == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left and right) return root;
        return left ? left : right;
    }
    int findDistance1(TreeNode* root, int p, int q) {
        TreeNode* lcaNode = lca(root, p, q);
        return distance(lcaNode, p) + distance(lcaNode, q);
    }
    int findDistance2(TreeNode* root, int p, int q) {
        TreeNode* lcaNode = lca(root, p, q);
        queue<pair<TreeNode*,int>>bfs;
        bfs.push({lcaNode,0});

        int totalDepth=0;
        int curDepth;
        int found=0;
        while(!bfs.empty() and found != 2){
            auto cur = bfs.front();
            bfs.pop();

            if(cur.first->val == p){
                found++;
                totalDepth += cur.second;
            }

            if(cur.first->val == q){
                found++;
                totalDepth += cur.second;
            }

            if(cur.first->left)
                bfs.push({cur.first->left, cur.second+1});
            if(cur.first->right)
                bfs.push({cur.first->right, cur.second+1});
        }
        return totalDepth;
    }
    int distance(TreeNode* root, int p, int q, int& pDist, int& qDist, int dist){
        if(!root) return 0;
        int left = distance(root->left, p, q, pDist, qDist, dist+1);
        int right = distance(root->right, p, q, pDist, qDist, dist+1);
        
        if(root->val == p){
            pDist = dist;
            return dist;
        }
        if(root->val == q){
            qDist = dist;
            return dist;
        }
        
        if(left and right) return dist;
        return left ? left : right;

    }
    int findDistance(TreeNode* root, int p, int q) {
        int pDist=-1, qDist=-1;
        int dist = distance(root, p, q, pDist, qDist, 0);
        if(pDist == -1 or qDist == -1) return 0;
        return pDist + qDist - 2*dist;
    }
};