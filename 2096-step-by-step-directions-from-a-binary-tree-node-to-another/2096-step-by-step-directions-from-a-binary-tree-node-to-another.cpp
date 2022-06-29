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
    bool getPath(TreeNode* root, int destination, string& path)
    {
        if(!root)
            return false;
        
        if(root->val == destination)
            return true;

        if(getPath(root->left, destination, path))
        {
            path += "L";
            return true;
        }
           
        if(getPath(root->right, destination, path))
        {
            path += "R";
            return true;
        }

        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path1, path2;
        getPath(root, startValue, path1);
        getPath(root, destValue, path2);
        
        while(!path1.empty() && !path2.empty() && path1.back() == path2.back())
        {
            path1.pop_back();
            path2.pop_back();
        }
        
        return string(path1.size(), 'U') + string(rbegin(path2), rend(path2));
    }
};