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
    ListNode* frontPtr;
    
    bool helper(ListNode* cur)
    {
        if(cur)
        {
            if(!helper(cur->next))
                return false;
            if(frontPtr->val != cur->val)
                return false;
            frontPtr = frontPtr->next;
        }
        
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        
        frontPtr = head;
        return helper(head);
    }
};