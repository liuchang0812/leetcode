#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            if (nums.size() == 0) 
                return 0;
            int sz = nums.size();
            nums.insert(nums.begin(), 1);
            nums.push_back(1);
             
            int dp[505][505];
            memset(dp, 0, sizeof dp);
            for (int len=1; len<=sz; ++len)
            {
                for (int i=1; i+len-1<=sz; ++i)
                {
                    int lft = i; 
                    int rht = i+len-1;
                    
                    dp[lft][rht] = 0;
                    for (int k = lft; k <= rht; ++k)
                    {
                        dp[lft][rht] = max(dp[lft][rht], nums[k]*nums[lft-1]*nums[rht+1] + dp[lft][k-1] + dp[k+1][rht]);
                    }

                    cerr << lft << ' ' << rht << ' ' << dp[lft][rht] << endl;
                }
            }
            return dp[1][sz];
    }
};

// Recursion
class Solution2 {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
        return burst(nums, dp, 1 , n);
    }
    int burst(vector<int> &nums, vector<vector<int> > &dp, int left, int right) {
        if (left > right) return 0;
        if (dp[left][right] > 0) return dp[left][right];
        int res = 0;
        for (int k = left; k <= right; ++k) {
            res = max(res, nums[left - 1] * nums[k] * nums[right + 1] + burst(nums, dp, left, k - 1) + burst(nums, dp, k + 1, right));
        }
        dp[left][right] = res;
        cerr << left << ' ' << right << ' ' << res << endl;
        return res;
    }
};

int main()
{

    // [7,9,8,0,7,1,3,5]
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(0);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    // nums.push_back(2);
    cout << Solution().maxCoins(nums) << endl;
    return 0;
}
