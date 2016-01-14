#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void insert_ans(vector<string>& ans, vector<int>& current_path)
    {
        stringstream ss;
        for (size_t i=0; i<current_path.size(); ++i)
        {
            ss << current_path[i];
            if (i!=current_path.size()-1) ss << "->";
        }
        ans.push_back(ss.str());
    }

    void
    dfs(vector<string>& ans, vector<int>& current_path, TreeNode* root)
    {
        if (root == NULL) return;

        current_path.push_back(root->val);
        if (root->left==NULL && root->right==NULL)
        {
            insert_ans(ans, current_path);
        }

        if (root->left)
            dfs(ans, current_path, root->left);

        if (root->right)
            dfs(ans, current_path, root->right);

        current_path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> ans;
       vector<int> path;
       dfs(ans, path, root);
       return ans;
    }
};
