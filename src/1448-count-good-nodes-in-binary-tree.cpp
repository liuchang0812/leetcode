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
    int goodNodes(TreeNode* root, int maxv=-1000000) {
        if (root == nullptr) return 0;
        if (root->val < maxv) {
            return goodNodes(root->left, maxv) + goodNodes(root->right, maxv);
        } else {
            return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
        }
    }
};
