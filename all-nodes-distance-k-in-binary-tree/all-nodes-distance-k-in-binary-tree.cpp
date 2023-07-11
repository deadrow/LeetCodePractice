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
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            if(root->left)
            {
                adjMap[root].push_back(root->left);
                adjMap[root->left].push_back(root);
            }
            
            if(root->right)
            {
                adjMap[root].push_back(root->right);
                adjMap[root->right].push_back(root);
            }

            inorder(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);

        unordered_set<TreeNode*>visited;
        queue<pair<TreeNode*, int>>bfs;
        bfs.push({target, 0});
        visited.insert(target);

        vector<int>ret;

        while(!bfs.empty())
        {
            auto cur = bfs.front();
            bfs.pop();

            if(cur.second == k)
            {
                ret.push_back(cur.first->val);
                continue;
            }

            for(auto v : adjMap[cur.first])
            {
                if(!visited.count(v))
                {
                    bfs.push({v, cur.second+1});
                    visited.insert(v);
                }
            }
        }

        return ret;
    }
};