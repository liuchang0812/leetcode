/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int ans[400];
        memset(ans, 0, sizeof ans);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
    }
};
// @lc code=end

