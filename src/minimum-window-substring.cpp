#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

void pnt_queue(const deque<char>& q);

class Solution {
public:
    string minWindow(string s, string t) {
        deque<char> Q;
        map<char, int> cnt;
        map<char, int> cntt;
        map<char, bool> chars;

        for (auto c:t)
        {
            chars[c] = true;
            cntt[c] ++;
        }
        int minn = INT_MAX;
        string ans;

        int ok = false;
        for (size_t i=0; i<s.size(); ++i)
        {
            //cout << i << ' ';  pnt_queue(Q);
            char c = s[i];

            Q.push_back(c);
            if (chars[c]) 
                cnt[c]++;

            while (!Q.empty())
            {
                char c = Q.front();
                if (chars[c] && cnt[c] > cntt[c] || !chars[c])
                {
                    cnt[c] --;
                    Q.pop_front();
                }
                else
                    break;
            }
            if (!ok)
            {
                size_t j;
                for(j=0; j<t.size(); ++j)
                    if (chars[t[j]] && cnt[t[j]] < cntt[t[j]])
                        break;
                if (j==t.size()) ok = true;
            }

            if (ok && Q.size() < minn)
            {
                minn = Q.size();
                ans = s.substr(i-minn+1, minn);
            }
        }
        return ans;
    }
};

void pnt_queue(const deque<char>& q)
{
    for (auto c:q)
        cout << c ;
    cout << endl;
}

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        cout << Solution().minWindow(s, t) << endl;
    }
    return 0;
}
