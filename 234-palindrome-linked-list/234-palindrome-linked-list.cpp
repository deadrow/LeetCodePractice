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
    ListNode* getMid(ListNode* head)
    {
        // find mid
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
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
    
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        
        // find mid
        ListNode* mid = getMid(head);
        ListNode* secondHalf = reverseList(mid->next);
        
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool res = true;
        while(res && p2)
        {
            if(p1->val != p2->val)
                res = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        mid->next = reverseList(secondHalf);
        return res;
    }
};