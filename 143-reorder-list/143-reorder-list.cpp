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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* prev = head;
        ListNode* next = head->next;
        ListNode* remain = reverseList(next);
        next->next = prev;
        prev->next = nullptr;
        return remain;
    }
    
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* reversedFromMid = reverseList(mid);
        
        // Now merge
        ListNode* it1 = head;
        ListNode* it2 = reversedFromMid;
        while(it1 && it2)
        {
            ListNode* temp = it2;
            it2 = it2->next;
            
            temp->next = it1->next;
            it1->next = temp;
            it1 = it1->next->next;
        }
        
    }
};