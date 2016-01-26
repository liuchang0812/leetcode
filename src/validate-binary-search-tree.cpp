#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, long long minLimit, long long maxLimit)
    {
        if (root==NULL) return true;
        long long val = root->val;
        int ret = val >= minLimit && val <= maxLimit;
        return ret && dfs(root->left, minLimit, val-1) && dfs(root->right, val+1, maxLimit);
    }

    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;

        return dfs(root, INT_MIN, INT_MAX);
    }
};
