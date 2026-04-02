/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        std::map<Node*, Node*> assoc;

        Node *res = new Node(head->val);
        res->random = head->random;
        assoc[head] = res;
        Node *prev = res;
        Node *tmp = head->next;

        while (tmp) {
            Node *newNode = new Node(tmp->val);
            prev->next = newNode;

            newNode->random = tmp->random;
            assoc[tmp] = newNode;

            prev = newNode;
            tmp = tmp->next;
        }

        tmp = res;
        while (tmp) {
            tmp->random = assoc[tmp->random];
            tmp = tmp->next;
        }

        return res;
    }
};
