/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root==NULL) return vector<int>();
        vector<int> ans;
        stack<TreeNode*> _stack;
        _stack.push(root);
        stack<TreeNode*> storage;
        while (!_stack.empty()) {
            TreeNode* cur;
            cur = _stack.top(); _stack.pop();
            if (cur != NULL)
            {
                _stack.push(cur->left);
                _stack.push(cur->right);
                storage.push(cur);
            }
        }
        while( !storage.empty()) {
            ans.push_back(storage.top()->val);
            storage.pop();
        }
        return ans;
    }
};
