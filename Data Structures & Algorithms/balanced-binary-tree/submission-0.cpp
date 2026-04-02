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

    std::pair<int, bool> aux(TreeNode* root) {
        if (!root)
            return {0, true};
        
        auto r = aux(root->right);
        if (!r.second)
            return {-1, false};
        auto l = aux(root->left);
        if (!l.second)
            return {-1, false};

        if (std::abs(r.first - l.first) > 1)
            return {-1, false};
        
        return {1 + std::max(r.first, l.first), true};
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        auto res = aux(root);
        return res.second;
    }
};
