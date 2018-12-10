#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> ps = {0};
        for (int i=0; i<nums.size(); ++i) {
            ps.push_back(ps.back() + nums[i]);
        }

        int ans = 0;
        map<long long, long long> cnt;
        cnt[0] = 1;

        for (int i=1; i<=nums.size(); ++i) {
            long long t = ps[i];
            long wantH = t - lower;
            long wantL = t - upper;
            //cout << "turn " << i << ' ' << wantL << ' ' << wantH << ' ' << t << endl;
            for (long long j=wantL; j <= wantH; ++j) 
            {
                if (cnt[j]) {
                  //cout << "add " << i  << ' ' << j << ' ' << cnt[j] <<  endl;
                  ans += cnt[j];
                }
            }
            ++ cnt[t];
        }
        return ans;
    }
};

int main() {

    vector<int> inp = {-2147483647,0,-2147483647,2147483647};
    int lower = -564;
    int upper = 3864;
    Solution sol;
    cout << sol.countRangeSum(inp, lower, upper) << endl;
    return 0;
}


// [-2147483647,0,-2147483647,2147483647]
// 3864
