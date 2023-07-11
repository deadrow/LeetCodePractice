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
        queue<TreeNode*>bfs;
        bfs.push(target);
        visited.insert(target);

        vector<int>ret;
        int steps = 0;
        
        while(!bfs.empty())
        {
            if(steps == k)
            {
                break;
            }

            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                auto cur = bfs.front();
                bfs.pop();

                for(auto v : adjMap[cur])
                {
                    if(!visited.count(v))
                    {
                        bfs.push(v);
                        visited.insert(v);
                    }
                }
            }

            steps++;
        }

        while(!bfs.empty())
        {
            auto cur = bfs.front();
            bfs.pop();
            ret.push_back(cur->val);
        }

        return ret;
    }
};