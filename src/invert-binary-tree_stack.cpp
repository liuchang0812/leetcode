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
    TreeNode* invertTree(TreeNode* root) {
        typedef stack<TreeNode*> TreeNodeStack;
        TreeNodeStack _stack;
        _stack.push(root);
        
        while (!_stack.empty())
        {
            TreeNode* cur = _stack.top(); _stack.pop();
            if (cur == NULL) continue;
            swap(cur->left, cur->right);
            _stack.push(cur->left);
            _stack.push(cur->right);
        }
        return root;
    }
};
