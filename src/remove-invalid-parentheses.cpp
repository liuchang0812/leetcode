#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int maxLen = INT_MAX;
    void dfs(string &s, int len, int curPos, int leftPareNum, int delNum, vector<bool> &deleted, vector<string> &ans)
    {
        if (curPos == len && leftPareNum == 0)
        {
            if (delNum <= maxLen)
            {
                // ans append
                maxLen = delNum;
                string tmp;
                for (int i=0;i < len; ++i)
                    if (!deleted[i]) tmp += s[i];
                ans.push_back(tmp);
                return;
            }
            return;
        }

        if (delNum > maxLen)
            return;

        if (leftPareNum > len-curPos)
            return;

        if (s[curPos] != '(' && s[curPos] != ')')
        {
            deleted[curPos] = false;
            dfs(s, len, curPos+1, leftPareNum, delNum, deleted, ans);
        }
        else
        {
            // no del
            if (s[curPos] == '(')
            {
                deleted[curPos] = false;
                dfs(s, len, curPos+1, leftPareNum+1, delNum, deleted, ans);
            }
            else
            {
                if (leftPareNum > 0)
                {
                    deleted[curPos] = false;
                    dfs(s, len, curPos+1, leftPareNum-1, delNum, deleted, ans);
                }
            }

            //del
            if (s[curPos] == ')')
            {
                deleted[curPos] = true;
                dfs(s, len, curPos+1, leftPareNum, delNum+1, deleted, ans);
                deleted[curPos] = false;
            }
            else
            {
                deleted[curPos] = true;
                dfs(s, len, curPos+1, leftPareNum, delNum+1, deleted, ans);
                deleted[curPos] = false;
            }
        }

    }

    vector<string> removeInvalidParentheses(string s) {
       vector<string> ans; 
       int len = s.size();
       vector<bool> deleted;
       deleted.resize(len);
       //cout << deleted.size() << endl;
       dfs(s, len, 0, 0, 0, deleted, ans);
       sort(ans.begin(), ans.end());
       ans.erase(unique(ans.begin(), ans.end()), ans.end());
       return ans;
    }
};


int main()
{
    string tmp;
    vector<string> ans;
    while (cin >> tmp)
    {
        //cout << Solution().removeInvalidParentheses(tmp).size() << endl;
        ans = Solution().removeInvalidParentheses(tmp);
        for (auto i:ans)
            cout << i << endl;
    }
    return 0;
}
