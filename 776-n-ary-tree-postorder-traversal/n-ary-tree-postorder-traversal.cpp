/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>ret;
    void helper(Node* root){
        if(!root) return;
        for(auto it : root->children)
            helper(it);
        ret.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        helper(root);
        return ret;
    }
};