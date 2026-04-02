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
    void dfs(TreeNode *root, int k, int &cnt, int &res) {
        if (!root) 
            return;

        dfs(root->left, k, cnt, res);

        cnt += 1;

        std::cout << root->val << std::endl;
        if (k == cnt) {
            std::cout << "poop" << std::endl;
            res = root->val;
        }

        dfs(root->right, k, cnt, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int cnt = 0;

        dfs(root, k, cnt, res);

        return res;
    }
};
