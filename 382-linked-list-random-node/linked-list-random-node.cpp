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
    // reservoir sampling
    ListNode* _head;
    Solution(ListNode* head): _head(head) {
        
    }
    
    int getRandom() {
        int nodesTillNow = 0;
        ListNode* cur = _head;

        ListNode* random;
        while(cur) {
            nodesTillNow++;
            if(rand()%nodesTillNow == nodesTillNow-1) random = cur;
            cur = cur->next;
        }
        return random->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */