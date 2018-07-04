#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWaysBF(vector<int>& nums, int S) {
        int n = nums.size(); 
        int ans = 0;
        int tmp;
        for (int i=0; i<(1<<n); ++i)
        {
            tmp = 0;
            for (int j=0; j<n; ++j) {
                if (i&(1<<j)) tmp -= nums[j];
                else tmp += nums[j];
            }
            ans += tmp == S;
        }
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000) return 0;
        int dp[21][2005];
        memset(dp, 0, sizeof dp);
        // 1001 == 0
        dp[0][1001] = 1;
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<=2001; ++j) {
                int tmp = 0;
                if (j-nums[i] >=0 && j-nums[i] <= 2001)
                    tmp += dp[i][j-nums[i]];
                if (j+nums[i] >= 0 && j + nums[i] <= 2001)
                    tmp += dp[i][j+nums[i]];
                dp[i+1][j] = tmp;
            }
        }
        return dp[nums.size()][S+1001];
    }
};

int main() {
    Solution sol;
    vector<int> inp = {25,29,23,21,45,36,16,35,13,39,44,15,16,14,45,23,50,43,9,15};
    cout << sol.findTargetSumWays(inp, 32) << endl;
    cout << sol.findTargetSumWaysBF(inp, 32) << endl;
    return 0;
}
