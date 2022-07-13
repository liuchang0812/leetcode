/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
public:

    int characterReplacement(string s, int k) {
        int ans = 1;
        int bg, ed;
        bg  = 0;
        ed = 1;
        int cnt[26];
        memset(cnt, 0, sizeof cnt);

        cnt[s[bg]-'A'] = 1;

        for (; ed < s.size(); ++ ed) {
            cnt[s[ed]-'A'] ++;
            
            while (true) {

                int maxlen = 0;
                char maxchar = s[ed];

                for (int i=0; i<26; ++i) {
                    if (cnt[i] > maxlen) {
                        maxlen = cnt[i];
                        maxchar = 'A' + i;
                    }
                }
                if (ed - bg + 1 - maxlen > k) { --cnt[s[bg]-'A']; ++bg; }
                else break;
            }
            printf("ed bg ans %d %d %d\n", ed, bg, ans);
            ans = max(ans, ed - bg + 1);
        }
        return ans;
    }
};
// @lc code=end

