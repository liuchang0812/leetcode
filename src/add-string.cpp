#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int jw = 0;
        
        for (int i=0; i<max(num1.size(), num2.size()); ++i)
        {
            int tmp = 0;
            if (i < num1.size()) tmp += num1[i] - '0';
            if (i < num2.size()) tmp += num2[i] - '0';
            tmp += jw;
            cout << tmp << ' ' << jw << endl;
            ret += char(tmp % 10 + '0');
            jw = tmp / 10;
        }
        if (jw) ret += char(jw+'0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    string s1, s2;
    Solution sol;
    while (cin >> s1 >> s2)
    {
        cout << sol.addStrings(s1, s2) << endl;
    }
    return 0;
}
