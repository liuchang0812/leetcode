#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {

    vector<int> dp;
    dp.resize(amount+1);
    fill(dp.begin(), dp.end(), -1);

    for (auto i:coins)
    {
        if (i<=amount) 
            dp[i] = 1;
    }

    for (int i = 0; i <= amount; i++)
    {
        if (i==0) {dp[i] = 0;continue;}
        if (dp[i] != -1) continue;

        int minv = INT_MAX;
        for (auto j:coins)
        {
            if (i-j >= 0 && dp[i-j]!=-1)
                minv = min(minv, dp[i-j]);
        }
        if (minv != INT_MAX)
        dp[i] = minv + 1;
        //cerr << i << ' ' << dp[i] << endl;
    }

    return dp[amount];
    }
};

int main()
{
    vector<int> inp;
    //inp.push_back(1); inp.push_back(2); inp.push_back(5);
    inp.push_back(2);
    cout << Solution().coinChange(inp, 3) << endl;


    return 0;
}
