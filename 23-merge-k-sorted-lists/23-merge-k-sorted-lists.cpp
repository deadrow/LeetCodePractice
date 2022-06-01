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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        if(lists.size() == 1)
            return lists[0];
        
        int interval = 1;
        while(interval < lists.size())
        {
            for(int i =0;i+interval<lists.size();i+=interval*2)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            
            interval *= 2;
        }
        
        return lists[0];
    }
};