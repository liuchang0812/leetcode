class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int len = s.size();
        int base = 1;
        for (int i = len-1; i>= 0; i--)
        {
            ans += (s[i] -'A' + 1)*base;
            base *= 26;
        }
        return ans;
    }
};
