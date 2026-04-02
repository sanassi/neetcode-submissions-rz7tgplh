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
    void aux(ListNode *cur, ListNode* prev, ListNode **newHead, int& n) {
        if (!cur)
            return;
        aux(cur->next, cur, newHead, n);
        n -= 1;

        if (n == 0) {
            //std::cout << "val: " << cur->val << std::endl;
            if (!prev) {
                *newHead = cur->next;
            }
            else
                prev->next = cur->next;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
        ListNode *newHead = head;
        aux(head, nullptr, &newHead, n);

        return newHead;
    }
};
