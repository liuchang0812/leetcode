class Solution {
public: 
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return (abs(deep(root->left) - deep(root->right)) <= 1) &&
                isBalanced(root->left) &&
                isBalanced(root->right);
    }
private:
    int deep(TreeNode* root) {
        if (root == NULL) return 0;
        return max(deep(root->left), deep(root->right)) + 1;
    }
};
