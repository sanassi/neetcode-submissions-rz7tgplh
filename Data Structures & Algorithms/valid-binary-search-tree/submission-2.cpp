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
    bool aux(TreeNode *r, int l, int h) {
        if (!r)
            return true;

        if (r->val <= l || r->val >= h)
            return false;

        return aux(r->right, r->val, h) && aux(r->left, l, r->val);       
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return aux(root, -INT_MAX, INT_MAX);
    }
};
