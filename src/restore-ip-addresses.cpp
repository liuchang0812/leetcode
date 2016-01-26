#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string formIpStr(vector<string> strs)
    {
        string ans;
        for (auto s:strs)
        {
            ans = ans + s + '.';
        }
        ans.resize(ans.size()-1);
        return ans;
    }

    void dfs(const string &s, int cur_pos, int cur_seg, vector<string> &cur_ans, vector<string> &ans)
    {
        if (cur_pos >= s.size() && cur_seg == 4)
        {
            string tmp = formIpStr(cur_ans);
            cout << "Get One " << tmp << endl;
            ans.push_back(tmp);
            return;
        }
        else if (cur_seg == 4)
            return;
        else
        {
            for (size_t len=1; len<=3 && cur_pos+len<s.size(); ++len)
            {
                string sub = s.substr(cur_pos, len);
                if (str2int(sub) < 256)
                {
                    cur_ans.push_back(s.substr(cur_pos, len));
                    dfs(s, cur_pos + len, cur_seg+1, cur_ans, ans);
                    cur_ans.pop_back(); 
                }
            }
        }
    }

    int str2int(string s)
    {
        if (s == "0") return 0;
        else if (s[0] == '0') return INT_MAX;
        int ans = 0;
        for (auto c:s)
        {
            ans = ans * 10;
            ans += (c-'0');
        }
        return ans;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;        
        int len = s.size();

        if (len > 3*4 || len < 4)
            return ans;
        for (int i= 1; i<=3; ++i)
            for (int j=1; j<=3; ++j)
                for (int k=1; k<=3; ++k)
                {
                    int p1 = i;
                    int p2 = i+j;
                    int p3 = i+j+k;
                    if (len - p3 > 3 || p3 >= len) continue;

                    string s1, s2, s3, s4;

                    s1 = s.substr(0, i);
                    s2 = s.substr(i, j);
                    s3 = s.substr(i+j, k);
                    s4 = s.substr(p3);
                    //cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << endl;

                    if (str2int(s1) < 256 && str2int(s2) < 256 && str2int(s3) < 256 && str2int(s4) < 256)
                        ans.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                }
        //vector<string> cur_ans;
        //dfs(s, 0, 0, cur_ans, ans);
        return ans;
    }
};

int main()
{
    string s;
    while (cin>>s)
    {
        vector<string> ans;
        ans = Solution().restoreIpAddresses(s);
        for (auto s:ans)
            cout << s << endl;
    }
    return 0;
}
