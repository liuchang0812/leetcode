#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n<2) return 0;
        int f[n+5], rf[n+5];
        memset(f, 0, sizeof f);
        memset(rf, 0, sizeof rf);
        int minv = prices[0];
        f[0] = 0;
        for (int i=1; i<n; i++) {
            f[i] = max(f[i-1], prices[i] - minv);
            minv = min(minv, prices[i]);
        }  

        rf[n-1] = 0; 
        int maxv = prices[n-1];
        for (int i=n-2; i>=0; i--) {
            rf[i] = max(rf[i+1], maxv - prices[i]);
            maxv = max(maxv, prices[i]);
        }

        int ans = 0;
        for (int i=0; i<n; i++)
        {
            ans = max(ans, f[i] + rf[i+1]);
            cout << i << ' ' << f[i] << ' ' << rf[i+1] << ' ' << ans << endl;
        }
        ans = max(ans, f[n-1]);
        return ans;
    }
};

int main() {

    Solution sol;
    int n;
    cin >> n;
    vector<int> prices;
    for(int i=0;i < n;i ++) { int tmp; cin >> tmp; prices.push_back(tmp);}
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
