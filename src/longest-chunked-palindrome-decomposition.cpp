/*
 * @lc app=leetcode id=1147 lang=cpp
 *
 * [1147] Longest Chunked Palindrome Decomposition
 */

// @lc code=start
class Solution {
public:
    int longestDecomposition(string text) {
        int len = text.size();
        string text2 = text;
        reverse(text.begin(), text.end());

        bool isPali[1000][1000];
        memset(isPali, 0, sizeof isPali);
        for (int i=0; i<len/2; ++i)
            for (int j=i; j<len/2; ++j)
            {
                string tmp1 = text.substr(i, j-i+1);
                string tmp2 = text2.substr(i, j-i+1);
                reverse(tmp2.begin(), tmp2.end());
                if (tmp1 == tmp2)
                    isPali[i][j] = true;
                else
                    isPali[i][j] = false;
            }
        int dp[1000];
        int ans = 0;
        int ansP = 0;
        memset(dp, 0, sizeof dp);
        for (int i=0; i<len/2; ++i) {
            int tmp = 0;
            for (int j=0; j<=i; ++j) {
                if (isPali[j][i])
                    if (j==0) 
                        tmp = 1;
                    else 
                        if (dp[j-1] != 0)
                            tmp = max(tmp, dp[j-1]+1);
            }
            dp[i] = tmp;
            if (dp[i]>=ans) ans=dp[i], ansP=i;
            //cout << i << ' ' << dp[i] << endl;
        }
        ans *= 2;
        if (ans == 0) return 1;

        if (len %2 ) return ans+1;
        else {
            if (ansP != len/2-1) return ans+1;
            return ans;
        }

    }
};
// @lc code=end

