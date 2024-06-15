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
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* prev = nullptr;
        ListNode* cur = start;
        ListNode* endNext = end->next;
        while(cur != endNext){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* leftPart = head;
        ListNode* start = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for(int i=1;i<left;i++) {
            prev = start;
            start = start->next;
        }

        ListNode* end = head;
        for(int i=1;i<right;i++) {
            end = end->next;
        }
        
        ListNode* rightPart = end->next;
        end->next = nullptr;

        ListNode* rev = reverse(start, end);
        prev->next = rev;
        start->next = rightPart;
        return dummy->next;
    }
};