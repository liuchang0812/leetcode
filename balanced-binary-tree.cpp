
class Solution {
public: 
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return abs(deep(root->left) - deep(root->right)) <= 1; 
    }
private:
    int deep(TreeNode* root) {
        if (root == NULL) return 0;
        return max(root->left, root->right) + 1;
    }
};
