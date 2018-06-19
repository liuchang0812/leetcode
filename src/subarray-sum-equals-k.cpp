class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sums[20000];
        sums[0] = nums[0];
        for (int i=1; i<nums.size(); ++i)
            sums[i] = sums[i-1] + nums[i];

        map<int, int> sum2cnt;
        sum2cnt[0] = 1;

        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
             int dita = sums[i] - k;
             ans += sum2cnt[dita];
             sum2cnt[sums[i]] ++;
        }
        return ans;
    }
};

