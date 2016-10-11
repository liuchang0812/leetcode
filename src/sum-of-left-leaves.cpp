/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(ThreadNode* root, int left) {
        if (root == NULL)
            return 0;
            
        if (root->left == NULL && root->right == NULL && left)
            return root->left->val;
            
        return dfs(root->left, 1) + dfs(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 0);
    }
};
