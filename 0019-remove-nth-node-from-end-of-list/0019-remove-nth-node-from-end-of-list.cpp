class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* first = head;
        ListNode* second = head;

        // Move second pointer n+1 steps forward so that there's a gap of n nodes
        for (int i = 0; i < n; ++i) {
            second = second->next;
        }

        if(second == nullptr){
            return head->next;
        }

        // Move both pointers until second reaches end
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;

        return head;
    }
};