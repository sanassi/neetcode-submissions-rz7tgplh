/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    /*
    void ancestors(TreeNode *root, TreeNode *t, std::vector<TreeNode*> &r) {
        if (!root)
            return;

        r.push_back(root);

        if (root == t) {
            return;
        }

        ancestors(root->left, t, r);
        ancestors(root->right, t, r);

        if (r.back() != t) {
            r.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> r;
        ancestors(root, p, r);

        std::vector<TreeNode*> s;
        ancestors(root, q, s);

        return new TreeNode(5);
    }
    */

    TreeNode* aux(TreeNode *r, TreeNode *p, TreeNode *q) {
        if (!r) {
            return q;
        }

        if (p->val > r->val && q->val < r->val) {
            return r;
        }

        if (p->val > r->val && q->val > r->val) {
            return aux(r->right, p, q);
        }
        else if (p->val < r->val && q->val < r->val) {
            return aux(r->left, p, q);
        }

        return r;
    }

    // if p > q then p is in the right child of their lowest common ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return aux(root, p, q);
    }
};
