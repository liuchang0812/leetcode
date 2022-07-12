/*
 * @lc app=leetcode.cn id=1156 lang=cpp
 *
 * [1156] 单字符重复子串的最大长度
 */

// @lc code=start
class Solution {
public:
    int maxRepOpt1(string text) {

        vector<pair<char, int>> chcnt;
        map<char, int> chcntmap;

        int ch = text[0];
        int count = 1;
        for (int i=1; i<text.size(); ++i) {
            if (text[i] != ch) {
                chcnt.push_back(make_pair(ch, count));
                chcntmap[ch] ++;
                ch = text[i];
                count = 1;
            } else {
                ++count;
            }
        }
        
        chcnt.push_back(make_pair(ch, count));
        chcntmap[ch] ++;

        int ans = 0;
        for (int i=0; i < chcnt.size(); ++i) {
            if (chcntmap[chcnt[i].first] > 1) ans = max(ans, chcnt[i].second + 1);
        }
        for (int i=0; i < chcnt.size(); ++i) {
            ans = max(ans, chcnt[i].second);
            if (i + 2 < chcnt.size() && chcnt[i+1].second == 1 && chcnt[i+2].first == chcnt[i].first) {
                ans = max(ans, chcnt[i].second + chcnt[i+2].second + (chcntmap[chcnt[i].first] > 2));
            }
        }
        return ans;
    }
};
// @lc code=end

