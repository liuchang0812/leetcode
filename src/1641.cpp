/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        int f[55][5];
        for (int i=0; i<5; ++i)
            f[1][i] = 1;
        for (int i=2; i<=n; ++i) {
            int tmp = 0;
            for (int j=0; j<5; ++j) {
                tmp += f[i-1][j];
                f[i][j] = tmp;
            }
        }
        int ans = 0;
        for (int i=0; i<5; ++i) ans += f[n][i];
        return ans;
    }
};
// @lc code=end

