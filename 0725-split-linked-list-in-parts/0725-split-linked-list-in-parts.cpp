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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k,nullptr);

        ListNode* temp = head;
        int size = 0;
        while(temp){

            size++;
            temp = temp->next;

        }

        int minReqNodes = size / k;
        int remNodes = size%k;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        for(int i = 0 ; i < k ; i++){

            res[i] = curr;

            for(int cnt = 1; cnt <= minReqNodes + (remNodes > 0 ? 1 : 0 ) ; cnt++){
                prev = curr;
                if(curr)
                    curr = curr->next;
            }
            if(prev)
            prev->next = nullptr;
            remNodes--;
           
        }
        return res;
    }
};