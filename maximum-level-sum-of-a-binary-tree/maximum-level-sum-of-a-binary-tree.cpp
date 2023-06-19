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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        map<int, set<int>, greater<int>> dict;

        bfs.push(root);
        int level = 1;
        while(!bfs.empty())
        {
            int size = bfs.size();
            int sum = 0;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur = bfs.front();
                bfs.pop();
                sum += cur->val;

                if(cur->left)
                    bfs.push(cur->left);

                if(cur->right)
                    bfs.push(cur->right);
            }

            dict[sum].insert(level);
            level++;
        }

        if(dict.empty())
            return -1;

        return *(dict.begin()->second.begin());
    }
};