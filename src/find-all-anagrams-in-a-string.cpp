#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt1[26], cnt2[26];        
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);

        for (auto i:p)
            cnt1[i-'a'] ++;
        
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        for (int i=0; i<p.size(); ++i)
            cnt2[s[i]-'a'] ++;

        int i=p.size();
        do
        {
            int j=0;
            for(; j<26; ++j)
                if (cnt1[j] != cnt2[j]) break;
            if (j == 26)
                ans.push_back(i-p.size());
            cnt2[s[i]-'a'] ++;
            cnt2[s[i - p.size()]-'a'] --;
            i++;
        }while (i<=s.size());

        return ans;
    }
};

int main()
{
    string s1, s2;
    Solution sol;
    while (cin >> s1 >> s2)
    {
        auto ret = sol.findAnagrams(s1, s2);
        for (auto i:ret)
            cout << i << ' ' ;
        cout << endl;
    }
    return 0;
}
