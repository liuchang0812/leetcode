/*
 * @lc app=leetcode.cn id=2248 lang=cpp
 *
 * [2248] 多个数组求交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> cnt;
        for (auto& i: nums) {
            for (auto& j: i) {
                ++cnt[j];
            }
        }
        vector<int> ans;
        for (auto p=cnt.begin(); p!=cnt.end(); ++p) {
            if (p->second == nums.size()) ans.push_back(p->first);
        }
        return ans;
    }
};
// @lc code=end

