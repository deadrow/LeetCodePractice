/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    bool isChildOf(Node* p, Node * q) {
        if(!p) return false;
        if(p == q) return true;
        bool child = false;
        child = isChildOf(p->parent,q);
        return child;
    }
    Node* traverse(Node* p, Node * q) {
        if(!p or !q) return nullptr;
        Node* parentP = traverse(p->parent,q);
        Node* parentQ = traverse(p,q->parent);
        if(p == q) return p;
        if(p == parentQ) return p;
        if(parentP == q) return q;
        return parentP == parentQ ? parentP : nullptr;
    }

    Node* lowestCommonAncestor(Node* p, Node * q) {
        // if p is child of q
        if(isChildOf(p,q)) return q;
        if(isChildOf(q,p)) return p;
        return traverse(p,q);
    }
};