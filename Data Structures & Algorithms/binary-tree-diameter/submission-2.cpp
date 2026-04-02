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
    int aux(TreeNode *root, int &max) {
        if (!root)
            return 0;
        
        int r = aux(root->right, max);
        int l = aux(root->left, max);

        max = std::max(max, r + l);

        return std::max(r, l) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        aux(root, res);

        return res;
    }
};
