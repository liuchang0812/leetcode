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
    vector<int> inorderTraversal(TreeNode *root) {
        if (root==NULL) return vector<int>();
        vector<int> ans;
        stack<TreeNode*> stack_;
        TreeNode* p = root;
        while(!stack_.empty() || p!=NULL)
        {
            while(p!=NULL)
            {
                stack_.push(p);
                p = p->left;
            }
            if(!stack_.empty())
            {
                p = stack_.top();
                ans.push_back(p->val);
                stack_.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
