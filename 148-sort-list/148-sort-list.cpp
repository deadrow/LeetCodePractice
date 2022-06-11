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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = nullptr;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        if(list1->val <= list2->val)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        
        return result;
    }
    
    ListNode* findMid(ListNode* head)
    {    
        // Find out mid and last
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Break the list in 2 halves
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* mid = findMid(head);
        
        // Now merge
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeTwoLists(left, right);
    }
};