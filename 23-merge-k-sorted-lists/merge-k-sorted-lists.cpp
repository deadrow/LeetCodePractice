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
    // Heap solution
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
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

    // divide and concur solution
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto retListFn = [&](ListNode* a, ListNode* b) {
            ListNode* ret = new ListNode(0);
            ListNode* ptr = ret;
            while(a && b) {
                if(a->val <= b->val) {
                    ptr->next = a;
                    a = a->next;
                } else {
                    ptr->next = b;
                    b = b->next;
                }
                ptr = ptr->next;
            }

            if(!a)
                ptr->next = b;
            else
                ptr->next = a;

            return ret->next;
        };

        if(lists.empty())
            return nullptr;

        int interval = 1;
        while(interval < lists.size()) {
            for(int i=0;i+interval<lists.size();i+= interval*2) {
                lists[i] = retListFn(lists[i], lists[i+interval]);
            }

            interval *= 2;
        }

        return lists[0];

    }
};