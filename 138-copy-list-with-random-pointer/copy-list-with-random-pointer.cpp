/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>oldToNew;
        Node* newHead = nullptr;
        Node* p1 = head;
        Node* p2 = newHead;
        while(p1){
            Node* node = new Node(p1->val);
            oldToNew[p1] = node;
            if(!p2){
                p2 = node;
                newHead = p2;
            }
            else {
                p2->next = node;
                p2 = p2->next;
            }
            p1 = p1->next;
        }

        // connect random 
        p1 = head;
        while(p1){
            Node* random = p1->random;
            Node* newRandom = oldToNew[random];
            oldToNew[p1]->random = newRandom;
            p1 = p1->next;
        }
        return newHead;
    }
};