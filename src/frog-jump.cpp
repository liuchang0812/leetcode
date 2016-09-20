#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<pair<int, int>, int > mem;  // 0 for no visited,   2 for succ, 3 for fail
    map<int, int> val2inx;

    bool dfs(const vector<int>& stones, int cur, int k)
    {
        if (cur >= stones.size()) return false;
        else if (cur == stones.size()-1)
            return true;
        else if (mem[make_pair(cur, k)] != 0)
            return mem[make_pair(cur, k)] == 2;
        else
        {
            int ret = false;
            for (int i=max(k-1, 1); i<=k+1; ++i)
            {
                int next = stones[cur] + i;
                if (val2inx[next] == 0) continue;
                if (dfs(stones, val2inx[next]-1, i))
                {
                    ret = true;
                    break;
                }
            }
            mem[make_pair(cur, k)] = ret?2:3;
            return ret;
        }
    }


    bool canCross(vector<int>& stones) {
        if (stones.size() < 2) return true;
        else if (stones[1] != 1) return false;
        for (int i=0; i<stones.size(); ++i)
            val2inx[stones[i]] = i+1;
        return dfs(stones, 1, 1);
    }
};

int main()
{
    int n;
    vector<int> vi;

    cin >> n;
    for (int i=0; i<n; ++i)
    {
        int tmp;
        cin >> tmp;
        vi.push_back(tmp);
    }
    Solution sol;
    cout << sol.canCross(vi) << endl;
    return 0;
}
