#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(vector<vector<int> > &ans, vector<int> &current_path, int current_sum, TreeNode* root, int sum)
    {
        if (root == NULL) return;

        current_path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && current_sum + root->val == sum) 
            ans.push_back(current_path);
        dfs(ans, current_path, current_sum + root->val, root->left, sum);
        dfs(ans, current_path, current_sum + root->val, root->right, sum);
        current_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int> > ans;
    vector<int> path;
    
    dfs(ans, path, 0, root, sum);
    return ans;    
    }
};
