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
    ListNode* aux(ListNode *cur, ListNode* prev) {
        if (!cur->next) {
            cur->next = prev;
            return cur;
        }
        auto c = aux(cur->next, cur);
        cur->next = prev;

        return c;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        return aux(head, nullptr);
    }
};
