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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> Q;
        queue<int> deep;
        Q.push(root);
        deep.push(1);
        int pre = 0;
        vector<vector<int> > ans;
        while (!Q.empty())
        {
            TreeNode* tmp = Q.front();Q.pop();
            int cur = deep.front(); deep.pop();
            if (tmp == NULL) continue;
            if (cur != pre)
            {
                ans.push_back(vector<int>());
                pre = cur;
            }
            ans[ans.size()-1].push_back(tmp->val);
            if (tmp->left) { Q.push(tmp->left); deep.push(cur+1);}
            if (tmp->right) { Q.push(tmp->right); deep.push(cur+1);}
        }
        return ans;
    }
};
