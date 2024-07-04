/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        if(root->left and root->right)
            root->left->next = root->right;
        if(root->right and root->next)
            root->right->next = root->next->left;
        
        Node* right = connect(root->right);
        Node* left = connect(root->left);
    
        return root;
    }
};