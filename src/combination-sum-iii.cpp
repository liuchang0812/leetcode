class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int cur, int curSum, int dep, int targetDep, int targetSum, vector<int>& nums)
    {
        if (dep > targetDep) return;
        if (curSum == targetSum && targetDep == dep)
            ans.push_back(nums);
        else
        {
            for (int i = cur+1; i <= min(9, targetSum - curSum); ++i)
            {
                nums.push_back(i);
                dfs(i, curSum + i, dep+1, targetDep, targetSum, nums);
                nums.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(0, 0, 0, k, n, tmp);
        return ans;
    }
};
