/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode* cur = head;
        while(cur)
        {
            len++;
            cur = cur->next;
        }
        
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        int diff = abs(lenA-lenB);
        if(lenA > lenB)
        {
            ListNode* curA = headA;
            while(curA && diff--)
                curA = curA->next;
            
            ListNode* curB = headB;
            while(curA && curB)
            {
                if(curA == curB)
                    return curA;
                curA = curA->next;
                curB = curB->next;
            }
            
        }
        else if(lenA < lenB)
        {
            ListNode* curB = headB;
            while(curB && diff--)
                curB = curB->next;
            
            ListNode* curA = headA;
            while(curA && curB)
            {
                if(curA == curB)
                    return curA;
                curA = curA->next;
                curB = curB->next;
            }
        }
        else
        {
            ListNode* curA = headA;
            ListNode* curB = headB;
            while(curA && curB)
            {
                if(curA == curB)
                    return curA;
                curA = curA->next;
                curB = curB->next;
            }
        }
        
        return nullptr;
    }
};