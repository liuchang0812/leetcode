#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> mem;
    map<pair<int, int>, bool> visited;

    bool dfs(string s, int pos_s, string p, int pos_p)
    {
        pair<int,int> pii = make_pair(pos_s, pos_p);

        if (visited[pii] == 1)
            return mem[pii];
        else
            visited[pii] = 1;

        if (pos_s == s.size() && pos_p == p.size()) 
        {
            mem[pii] = true;
            return true;
        }

        if (pos_s== s.size() || pos_p == p.size()) 
        {
            mem[pii] = false;
            return false;
        }

        if (p[pos_p] == '?') 
        {
            bool ret = dfs(s, pos_s+1, p, pos_p+1);
            mem[pii] = ret;
            return ret;
        }
        else if(p[pos_p] == '*')
        {
            if (pos_p > 0 && p[pos_p-1]=='*') 
            {
                bool ret = dfs(s, pos_s, p, pos_p+1);
                mem[pii] = ret;
                return ret;
            }

            for (size_t i=pos_s; i<=s.size(); ++i)
                if (dfs(s, i, p, pos_p+1))
                {
                    mem[pii] = true;
                    return true;
                }
            mem[pii] = false;
            return false;
        }
        else {
            if (s[pos_s] == p[pos_p])
            {
                bool ret = dfs(s, pos_s+1, p, pos_p+1);
                mem[pii] = ret;
                return ret;
            }
            else
            {
                mem[pii] = false;
                return false;
            }
        }
    } 

    bool isMatch(string s, string p) {
       return dfs(s, 0, p, 0); 
    }
};


int main()
{
    /*
    cout << Solution().isMatch("aa", "aa") << endl;
    cout << Solution().isMatch("aaa", "aa") << endl;
    cout << Solution().isMatch("aa", "*") << endl;
    cout << Solution().isMatch("aa", "a*") << endl;
    cout << Solution().isMatch("aa", "?*") << endl;
    cout << Solution().isMatch("aab", "c*a*b") << endl;
    */
    cout << Solution().isMatch("bbbabaabbbababbabaaababbbbbbaabbabbbbbaabbbbaabbbbbabaabbbaabbbbabababababbaaabbaabbabaaaaaaabbaaaabbaabbbbbaaaaaababaaaaaaaabbabbbabababaabaabaabbabbabaaaabbabaabbabbbbbbaaaaabbaabaabaababbbbbaabbbbbb",
            "*bba**a*a**a*bba******b*aa**b***aaa**a***aabbbb*ab***aaaa***bbbbbbbab*aaaabbb*bb*a**a**a*b***ab*b***") << endl;
    return 0;
}
