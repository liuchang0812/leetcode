/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define PushNode(x)  _stack.push(x)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> _stack;
        vector<int> ans;
        _stack.push(root);
        
        while( !_stack.empty())
        {
            TreeNode* node;
            node  = _stack.top();_stack.pop();
            if (node != NULL){
                ans.push_back(node->val);
                
                PushNode(node->right);
                PushNode(node->left);
            }
        }
        return ans;
    }
};

/*
使用一个栈来模拟递归操作
*/
