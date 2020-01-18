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
    int ans = 0;
    int sumEvenGrandparent(TreeNode* root, TreeNode* GP=nullptr, TreeNode* P=nullptr) {
        if (root == nullptr) return ans;
        if (GP && GP->val % 2 == 0) ans += root->val;
        sumEvenGrandparent(root->left, P, root);
        sumEvenGrandparent(root->right, P, root);
        return ans;
    }
};
