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
        
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>, decltype(compare)> pq(compare);

        for(ListNode* list : lists){

            if(list){
                pq.push(list);
            }
        }


        ListNode dummy;
        ListNode* tail = &dummy;

        while(!pq.empty()){

            ListNode* current = pq.top();
            pq.pop();

            tail->next = current;

            tail = tail->next;

            if(current->next){
                pq.push(current->next);
            }

        }

        return dummy.next;
    }
};