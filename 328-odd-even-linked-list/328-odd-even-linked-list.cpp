/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyOdd = new ListNode(0);
        ListNode* dummyEven = new ListNode(0);
        
        ListNode* cur = head;
        ListNode* tailOdd = dummyOdd;
        ListNode* tailEven = dummyEven;
        
        bool odd = true;
        while(cur)
        {
            if(odd)
            {
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = nullptr;
                
                tailOdd->next = temp;
                tailOdd = tailOdd->next;
            }
            else
            {
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = nullptr;
                
                tailEven->next = temp;
                tailEven = tailEven->next;
            }
            
            odd = !odd;
        }
        
        tailOdd->next = dummyEven->next;
        return dummyOdd->next;
    }
};