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
    bool canFormPalindrome(string& str)
    {
        int count[10] = { 0 };
 
        // For each character in input strings,
        // increment count in the corresponding
        // count array
        for (int i = 0; str[i]; i++)
            count[str[i]-'0']++;

        // Count odd occurring characters
        int odd = 0;
        for (int i = 0; i < 10; i++) {
            if (count[i] & 1)
                odd++;

            if (odd > 1)
                return false;
        }
 
        // Return true if odd count is 0 or 1,
        return true;
    }
    
    int helper(TreeNode* root, int cur)
    {
        if(!root)
            return 0;
        
        cur ^= (1 << root->val);
        if(!root->left && !root->right)
        {
            if((cur & (cur-1)) == 0)
                return 1;
            return 0;
        }
        
        return helper(root->left, cur) + helper(root->right, cur);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cur = 0;
        return helper(root, cur);
    }
};