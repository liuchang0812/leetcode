#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    map<pair<TreeNode*, int>, int> cache;
    int dfs(TreeNode* root, int flag)
    {
        if (root == NULL) return 0;

        if (cache[make_pair(root, flag)]!=0)
            return cache[make_pair(root, flag)];

        int ret;
        if (flag)
            ret = root->val + dfs(root->left, 1-flag) + dfs(root->right, 1-flag);
        else
            ret = max(dfs(root->left, 0), dfs(root->left, 1)) + max(dfs(root->right, 0), dfs(root->right, 1));
        cache[make_pair(root, flag)] = ret;
        return ret;
    }

    int rob(TreeNode* root) {
        return max(dfs(root, 0), dfs(root, 1));
    }
};
