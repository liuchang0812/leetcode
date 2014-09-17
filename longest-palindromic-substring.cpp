#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int len = s.size();
            int f[1001][1001];
            for (int i =0; i<len; ++i)
            {
                for (int j=0; j+i < len; ++j)
                {
                    int bg = j, ed = j + i;
                    if (bg == ed )
                        f[bg][ed] = 1;
                    else if(bg == ed -1)
                        f[bg][ed] = s[bg] == s[ed];
                    else
                        f[bg][ed] = f[bg+1][ed-1] && s[bg] == s[ed];
                }
            }
            for (int i =len-1; i >= 0; --i)
                for (int j = 0; j+i < len; ++j)
                {
                    if (f[j][i+j])
                        return s.substr(j, i+1);
                }
            return NULL;
        }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("asfddfsaasf") << endl;
    cout << s.longestPalindrome("xxxff") << endl;
    cout << s.longestPalindrome("x") << endl;
    return 0;
}
