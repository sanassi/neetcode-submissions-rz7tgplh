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
        int val = l1->val + l2->val;
        ListNode *res = new ListNode(val % 10);

        int carry = val / 10;

        ListNode *tmp = res;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            val = l1->val + l2->val + carry;
            carry = val / 10;
            tmp->next = new ListNode(val % 10);

            tmp = tmp->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 || l2) {
            while (l1) {
                val = l1->val + carry;
                carry = val / 10;
                tmp->next = new ListNode(val % 10);
                tmp = tmp->next;
                l1 = l1->next;
            }
            while (l2) {
                val = l2->val + carry;
                carry = val / 10;
                tmp->next = new ListNode(val % 10);
                tmp = tmp->next;
                l2 = l2->next;
            }
        }

        if (carry != 0) {
            tmp->next = new ListNode(carry);
        }

        return res;
    }
};
