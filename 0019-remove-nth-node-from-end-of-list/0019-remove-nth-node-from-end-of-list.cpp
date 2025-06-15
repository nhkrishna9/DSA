class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        // Move second pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            second = second->next;
        }

        // If second is null, it means we need to remove the head
        if (second == nullptr) {
            return head->next;
        }

        // Move both pointers until second reaches the last node
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        first->next = first->next->next;

        return head;
    }
};
