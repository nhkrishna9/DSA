class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  // new dummy node before head
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move second pointer n+1 steps forward so that there's a gap of n nodes
        for (int i = 0; i <= n; ++i) {
            second = second->next;
        }

        // Move both pointers until second reaches end
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from end
        ListNode* temp = first->next;
        first->next = first->next->next;
        delete temp;

        return dummy->next;
    }
};
