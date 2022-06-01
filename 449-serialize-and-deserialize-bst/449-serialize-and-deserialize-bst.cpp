/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string res;
    TreeNode* createTree(TreeNode* root, list<int>& nums)
    {
        if(nums.empty() ||  nums.front() == -1001)
        {
            nums.pop_front();
            return nullptr;
        }

        root = new TreeNode(nums.front());
        nums.pop_front();
        root->left = createTree(root->left, nums);
        root->right = createTree(root->right, nums);
        
        return root;
    }
    
    void preorder(TreeNode* root)
    {
        if(!root)
        {
            res += "-1001#";
            return;
        }
        
        res += to_string(root->val) + "#";
        preorder(root->left);
        preorder(root->right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preorder(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        list<int> tokens;
        string temp_str;

        while(getline(ss, temp_str, '#')) {
            if(!temp_str.empty())
                tokens.push_back(stoi(temp_str));
        }
        
        TreeNode* root = nullptr;
        root = createTree(root, tokens);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;