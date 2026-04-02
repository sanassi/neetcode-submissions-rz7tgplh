/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* aux(Node *node, std::map<Node*, Node*> &copies) {
        if (!node) 
            return nullptr;

        if (copies.find(node) != copies.end())
            return copies[node];

        Node *c = new Node(node->val);

        copies[node] = c;

        for (auto n : node->neighbors) {
            c->neighbors.push_back(aux(n, copies));
        }

        return c;
    }

    Node* cloneGraph(Node* node) {
        std::map<Node*, Node*> copies;

        aux(node, copies);

        return copies[node];
    }
};
