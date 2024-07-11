/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = nullptr;
    Node* prev = nullptr;
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        if(prev){
            prev->right = root;
            root->left = prev;
        } else {
            // since prev is not set. So it would be first node
            head = root;
        }
        prev = root;
        inorder(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        inorder(root);
        if(prev){
            cout << prev->val;
            prev->right = head;
            head->left = prev;
        }
        return head;
    }
};