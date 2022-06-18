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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> dict;
        
        ListNode* cur = headA;
        while(cur)
        {
            dict.insert(cur);
            cur = cur->next;
        }
        
        cur = headB;
        while(cur)
        {
            auto it = dict.find(cur);
            if(it != dict.end())
                return *it;
            cur = cur->next;
        }
        
        return nullptr;
    }
};