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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        unordered_set<int>mp(nums.begin(), nums.end());
        while(cur){
            if(cur->next and mp.count(cur->next->val))
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};