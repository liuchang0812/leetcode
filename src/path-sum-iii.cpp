
class Solution
{
public:
    void dfs(TreeNode* root, int sum, vector<int>& vi, int& ans)
    {
        if (root == NULL)
            return;

        for (int i=0; i<vi.size(); ++i)
            vi[i] = vi[i] + root->val;
        vi.push_back(root->val);

        for (auto i:vi)
            if (i==sum) ans++;

        dfs(root->left, sum, vi, ans);
        dfs(root->right, sum, vi, ans);

        vi.pop_back();
        for (int i=0; i<vi.size(); ++i)
            vi[i] = vi[i] - root->val;
    }

    int pathSum(TreeNode* root, int sum)
    {
        vector<int> sums;
        int ans;
        ans = 0;
        dfs(root, sum, sums, ans);
        return ans;
    }
};
