/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>>adjMap;
    TreeNode* traverse(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* left = traverse(root->left);
        TreeNode* right = traverse(root->right);
        if(left){
            adjMap[root].push_back(left);
            adjMap[left].push_back(root);
        }
        if(right){
            adjMap[root].push_back(right);
            adjMap[right].push_back(root);
        }
        return root;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverse(root);
        vector<int>ret;
        queue<pair<TreeNode*,int>>bfs;
        unordered_set<TreeNode*>visited;
        visited.insert(target);
        bfs.push({target,0});
        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();

            if(cur.second == k){
                ret.push_back(cur.first->val);
                continue;
            }

            for(auto& it : adjMap[cur.first]){
                if(!visited.count(it)){
                     bfs.push({it, cur.second+1});
                     visited.insert(it);
                }
                   
            }
        }

        return ret;
    }
};