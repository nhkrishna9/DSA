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
    ListNode* merge2SL(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode{};
        ListNode* tmp = dummy;
        while(l1!=nullptr && l2!= nullptr){
            if(l1->val <= l2->val){
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            else{
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr){
            tmp->next = l1;
        }
        if(l2 != nullptr){
            tmp->next = l2;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }

        if(lists.size()==1){
            return lists[0];
        }

        ListNode* merged = merge2SL(lists[0], lists[1]);

        for(int i=2; i<lists.size(); i++){
            merged = merge2SL(merged, lists[i]);
        }

        return merged;

        
    }
};