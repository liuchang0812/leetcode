#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> prettyPrint(const vector<int>& x)
    {
        int len = x.size();
        vector<string> ans;

        for (auto i:x)
        {
            string tmp = string(i, '.') + 'Q';
            tmp.resize(len, '.');
            ans.push_back(tmp);
        }
        return ans;
    }

    void dfs(vector<int>& cur, int cur_dep, int target, vector<vector<string> > &ans)
    {
        if (cur_dep == target)
        {
            // cout << "cur << ";
            // for (auto i:cur) cout << i << ' ' ;
            // cout << endl;

            ans.push_back(prettyPrint(cur));
            return;
        }
                for (int i=0; i<target; i++)
        {
            // row
            int ret = true;
            for (auto x: cur)
            {
                if (x == i)
                {
                    ret = false;
                    continue;
                }
            }

            if (ret)
            {
                for (size_t j=0; j<cur.size(); j++)
                {
                    if (abs(int(cur_dep-j)) == abs(i-cur[j]))
                    {
                        ret = false;
                        continue;
                    }
                }
            }
            if (ret)
            {
                cur.push_back(i);
                dfs(cur, cur_dep+1, target, ans);
                cur.pop_back();
            }
        }
    }
        vector<vector<string> > solveNQueens(int n) {
       vector<vector<string> > ans;
       vector<int> cur;
       dfs(cur, 0, n, ans);
       return ans;
    }
};

int main()
{

    int n;
    while(cin >> n)
    {
        vector<vector<string> > ans = Solution().solveNQueens(n);

        for (size_t i=0; i<ans.size(); ++i)
        {
            for (size_t j=0; j<ans[i].size(); ++j)
                cout << ans[i][j] << endl;

            cout << endl;
        }

    }
}
