#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    void dfs(map<int, int>& num2cnt, const vector<int> &uniqueNums, int cur_ord, vector<int> &cur_ans, vector<vector<int> > &ans)
    {
        if (cur_ord==uniqueNums.size())
        {
            ans.push_back(cur_ans);
            return;
        }
        else
        {
            int num = uniqueNums[cur_ord];
            int cnt = num2cnt[num];
            
            dfs(num2cnt, uniqueNums, cur_ord+1, cur_ans, ans);

            for (int i=1; i<=cnt; ++i)
            {
                for (int j=0; j<i; ++j)
                    cur_ans.push_back(num);
                dfs(num2cnt, uniqueNums, cur_ord+1, cur_ans, ans);
                for (int j=0; j<i; ++j)
                    cur_ans.pop_back();
            }
             
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        map<int, int> num2cnt;

        sort(nums.begin(), nums.end());
        for (auto i:nums)
            num2cnt[i] ++;

        auto last = unique(nums.begin(), nums.end());
        vector<int> uniqueNums = vector<int>(nums.begin(), last);
        
        vector<int> cur_ans;
        dfs(num2cnt, uniqueNums, 0, cur_ans, ans);
        return ans;
    }
};

int main()
{
    vector<int> inp;
    for (int i=0; i<10; i++)
    {
        inp.push_back(i/3);
    }
    vector<vector<int> > ans;
    ans = Solution().subsetsWithDup(inp);

    for (size_t i=0; i<ans.size(); ++i)
    {
        for (size_t j=0; j<ans[0].size(); ++j)
            cout << ans[i][j] << ' ' ;
        cout << endl;
    }

    return 0;
}
