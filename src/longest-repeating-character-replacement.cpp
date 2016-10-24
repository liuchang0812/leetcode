#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;
// 2 * 10000 * 26
class Solution {
public:
    int characterReplacement(string s, int k) {
		int bg, ed;
		int cnt[26];        
		int sumLen, maxLen, maxChar;
        if (s.empty() || s.size() == 0)
            return 0;
        // [bg, ed)
        bg = 0;
        ed = 1;
        memset(cnt, 0, sizeof cnt);
        sumLen = 1;
        maxLen = 1;
        maxChar = s[0];
        cnt[s[0]-'A'] = 1;

        int ans;
        ans = 1;

        for (; ed < s.size(); ++ed)
        {
            sumLen ++;
            cnt[s[ed]-'A'] ++;

            do
            {
                // choose bg
                int maxv = 0;
                int maxc = 0;
                for (int i=0; i<26; ++i)
                {
                    if (cnt[i] > maxv)
                    {
                        maxv = cnt[i];
                        maxc = i;
                    }
                }
                if (sumLen - maxv <= k) break;
                else
                {
                    cnt[s[bg] - 'A'] --;
                    bg ++;
                    sumLen --;
                }
            } while (true);
        ans = max(ans, sumLen);
        }
        return ans;
    }
};


int main()
{
    string s;
    int k;
    Solution sol;
    while (cin >> s >> k)
    {
        cout << sol.characterReplacement(s, k) << endl;
    }
    return 0;
}
