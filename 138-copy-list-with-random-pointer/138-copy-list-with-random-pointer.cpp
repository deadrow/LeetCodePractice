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
        unordered_map<Node*, Node*> dict;
        
        Node* cur = head;
        while(cur)
        {
            Node* newNode = new Node(0);
            newNode->val = cur->val;
            dict[cur] = newNode;
            
            cur = cur->next;
        }
        
        cur = head;
        while(cur)
        {
            dict[cur]->next = dict[cur->next]; 
            dict[cur]->random = dict[cur->random]; 
            cur = cur->next;
        }
        
        return dict[head];
    }
};