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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int length = 1;
        ListNode* cur = head;
        while(cur->next) {
            length++;
            cur = cur->next;
        }
        if((k % length) == 0) return head;
        k = length - k % length;

        // connect end to start
        cur->next = head;
        while(k--) cur = cur->next;
        ListNode* newHead = cur->next;
        cur->next = nullptr;
        return newHead;
    }
};