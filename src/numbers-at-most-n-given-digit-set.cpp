/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> int2vec(int N) {
        vector<int> ans;
        while(N!=0) {
            ans.push_back(N%10);
            N/=10;
        }
        return ans;
    }
    int toInt(string s) {
        int ans = 0;
        for (char c:s) 
            ans = ans * 10 + (c-'0');
        return ans;
    }

    int low_num(int s, vector<int>& nums) {
        int cnt = 0;
        for (auto i:nums) 
            cnt += i<s;
        return cnt;
    }

    bool has_num(int s, vector<int>& nums) {
        for (auto i: nums)
            if (i==s) return true;
        return false;
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> ds;
        for (auto& s:D)
            ds.push_back(toInt(s));
        
        vector<int> ns = int2vec(N);
        
/*         cout << "DS: " ;
        for (auto i:ds) cout << i << ' '; cout << endl;

        cout << "NS: "  ;
        for (auto i:ns) cout << i << ' '; cout << endl;
 */
        int f[15];
        f[0] = 1;
        int all = 1;
        for (int i=1; i<=ns.size(); ++i) {
            int tmp = 0;
            tmp += low_num(ns[i-1], ds) * all;
            all *= ds.size();
            if (has_num(ns[i-1], ds))
                tmp += f[i-1];
            f[i] = tmp;
            //cout << i << ' ' << f[i] << endl;
        }

        int ans = f[ns.size()];
        int tmp = 1;
        for (int i=1; i<ns.size(); ++i)
        {
            tmp *= ds.size();
            ans += tmp;
        }

        return ans;
        
    }
};
/*
int main() {
    Solution sol;
    vector<string> ds = {"1", "3", "5", "7"};
    cout << sol.atMostNGivenDigitSet(ds, 1100) << endl;
    return 0;
}
*/
// @lc code=end

