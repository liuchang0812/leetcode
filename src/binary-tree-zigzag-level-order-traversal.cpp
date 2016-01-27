class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& nums, vector<int>& levels)
    {
        if(root==NULL) return;
        nums.push_back(root->val);
        levels.push_back(level);
        dfs(root->left, level+1, nums, levels);
        dfs(root->right, level+1, nums, levels);
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root==NULL) return ans;
        vector<int> levels;
        vector<int> nums;

        dfs(root, 0, nums, levels);

        int maxLevel=0;
        for (auto i:levels)
            maxLevel = max(maxLevel, i);

        ans.resize(maxLevel+1);

        for (size_t i=0; i<nums.size(); ++i)
        {
            if (levels[i]%2==0)
                ans[levels[i]].push_back(nums[i]);
            else
                ans[levels[i]].insert(ans[levels[i]].begin(), nums[i]);
        }
        return ans;
    }
};
