#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> c2i;

        for (auto i:s)
            ++ c2i[i];
        int ans = 0;
        bool hasOdd=false;
        for(auto p:c2i)
        {
            ans += p.second/2*2;
            if (p.second&1)
                hasOdd=true;
        }
        if (hasOdd) ++ans;

        return ans;
    }
};

int main()
{

    Solution sol;
    cout << sol.longestPalindrome("ababd") << endl;
    return 0;
}
