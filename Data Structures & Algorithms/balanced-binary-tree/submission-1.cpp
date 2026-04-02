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
    int aux(TreeNode *root, bool& res) {
        if (!root)
            return true;
        
        int l = aux(root->left, res);
        int r = aux(root->right, res);

        if (std::abs(r - l) > 1) {
            res = false;
            return -1;
        }

        return 1 + std::max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        bool res = true;
        aux(root, res);
        return res;
    }
};
