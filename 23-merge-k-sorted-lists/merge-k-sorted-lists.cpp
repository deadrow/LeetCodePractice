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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq;

        for(auto it: lists) {
            if(it)
                pq.push(it);
        }
            

        ListNode* newList = new ListNode(0);
        ListNode* dummyNode = newList;

        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            dummyNode->next = top;
            dummyNode = dummyNode->next;

            if(top and top->next)
                pq.push(top->next);
        }

        return newList->next;
    }
};