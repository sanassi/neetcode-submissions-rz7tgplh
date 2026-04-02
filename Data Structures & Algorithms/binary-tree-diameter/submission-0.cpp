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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    void aux(TreeNode *root, int &m) {
        if (!root)
            return;

        int dl = maxDepth(root->left);
        int dr = maxDepth(root->right);

        m = std::max(m, dl + dr);

        aux(root->left, m);
        aux(root->right, m);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int m = 0;
        aux(root, m);

        return m;
    }
};
