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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *newHead = nullptr;
        if (list1->val < list2->val) {
            newHead = list1;
            list1 = list1->next;
        }
        else {
            newHead = list2;
            list2 = list2->next;
        }

        ListNode *tmp = newHead;

        while (list1 && list2) {
            ListNode *toPush = nullptr;
            if (list1->val < list2->val) {
                toPush = list1;
                list1 = list1->next;
            }
            else {
                toPush = list2;
                list2 = list2->next;
            }

            toPush->next == nullptr;
            tmp->next = toPush;
            tmp = toPush;
        }

        if (!list1) {
            tmp->next = list2;
        }
        else if (!list2) {
            tmp->next = list1;
        }

        return newHead;
    }
};
