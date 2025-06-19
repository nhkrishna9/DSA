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
        // Facing runtime errors with two pointers
        if(head==nullptr || head->next==nullptr || k==0){
            return head;
        }
        ListNode* curr = head;
        int length = 1;
        while(curr->next!=nullptr){
            ++length;
            curr = curr->next;
        }
        curr->next = head;
        k = k%length;
        k = length-k;

        while(k>0){
            curr = curr->next;
            k--;
        }

        head = curr->next;
        curr->next = nullptr;

        return head;
        /*
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0;i<k;i++){
            if(fast){
                fast = fast->next;
            }
        }
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next->next;
        slow->next = nullptr;

        return head;
        */
        
    }
};