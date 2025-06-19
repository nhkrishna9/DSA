class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev{nullptr};

        while (head != nullptr) {
            ListNode* first = head;
            ListNode* second = head->next;

            first->next = prev;
            prev = first;
            head = second;
        }

        return prev;
    }
};
