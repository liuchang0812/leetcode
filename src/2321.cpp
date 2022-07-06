/*
 * @lc app=leetcode.cn id=2321 lang=cpp
 *
 * [2321] 拼接数组的最大分数
 */

// @lc code=start
class Solution {
public:
    int diff(const vector<int>& nums1, const vector<int>& nums2, int idx) {
        int a = idx < nums1.size() ? nums1[idx] : 0;
        int b = idx < nums2.size() ? nums2[idx] : 0;
        return a - b;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int len = max(nums1.size(), nums2.size());
        vector<int> diffs;
        diffs.resize(len);

        for (int i=0; i<len; ++i) {
            diffs[i] = diff(nums1, nums2, i);
        }

        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0ll);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0ll);
        long long ans = 0;

        int maxsum = 0;
        int cursum = 0;
        for (int i=0; i<len; ++i) {
            if (cursum + diffs[i] >= 0) {
                cursum += diffs[i];
                maxsum = max(maxsum, cursum);
            } else {
                cursum = 0;
            }
        }
        ans = max(ans, maxsum + sum2);

        int minsum = 0;
        cursum = 0;
        for (int i=0; i<len; ++i) {
            if (cursum + diffs[i] <= 0) {
                cursum += diffs[i];
                minsum = min(minsum, cursum);
            } else {
                cursum = 0;
            }
        }
        ans = max(ans, sum1 - minsum);
        return ans;
    }
};
// @lc code=end

