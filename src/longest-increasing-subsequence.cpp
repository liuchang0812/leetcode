class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int f[20000];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            int maxn = 0;
            for (int j = 0; j < i; ++j )
                if (nums[i] > nums[j])
                    maxn = max(maxn, f[j]);
            f[i]  = maxn + 1;
        }
        int maxn = f[0];
        for (int i=1; i < nums.size(); ++i)
            maxn = max(maxn, f[i]);
        return maxn;
    }
};
