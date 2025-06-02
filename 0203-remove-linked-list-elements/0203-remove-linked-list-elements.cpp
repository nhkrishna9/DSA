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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;
        ListNode* toDel = nullptr;
        while(curr != nullptr){
            if(curr->val == val){
                prev->next = curr->next;
                toDel = curr;
            }
            else{
                prev = curr;
            }
            curr = curr -> next;
            if(toDel != nullptr){
                delete toDel;
                toDel = nullptr;
            }
        }

        ListNode* ans = tmp->next;
        delete tmp;
        return ans;
        
    }
};