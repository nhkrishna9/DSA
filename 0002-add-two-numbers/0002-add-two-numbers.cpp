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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l1tmp = l1;
        ListNode* l2tmp = l2;

        ListNode* ans = new ListNode();
        ListNode* curr = ans;

        int carry = 0;
        while (l1tmp != nullptr || l2tmp != nullptr) {
            int val1 = (l1tmp != nullptr) ? l1tmp->val : 0;
            int val2 = (l2tmp != nullptr) ? l2tmp->val : 0;

            int sum = (val1 + val2 + carry);
            carry = sum / 10;
            sum = sum % 10;

            ListNode* tmp = new ListNode(sum);
            curr->next = tmp;
            curr = curr->next;

            if (l1tmp != nullptr) l1tmp = l1tmp->next;
            if (l2tmp != nullptr) l2tmp = l2tmp->next;
        }

        if (carry != 0) {
            ListNode* tmp = new ListNode(carry);
            curr->next = tmp;
        }

        return ans->next;
    }
};
