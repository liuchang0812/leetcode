class Solution {
public:
    int tryx(vector<int>& arr, int x) {
        int ans = 0;
        for (int i=0;i<arr.size();++i)
            if (arr[i] > x ) ans += x;
            else ans += arr[i];
        return ans;
    }
    int findBestValue(vector<int>& arr, int target) {
        int _sum = std::accumulate(arr.begin(), arr.end(), 0);
        int ex = max(0, int(target / arr.size() - 1));
        int ans = ex;
        int del = INT_MAX;
        while (true) {
            int _v = tryx(arr, ex);
            if (abs(_v - target) < del) {
                del = abs(_v - target);
                ans = ex;
            }
            if (_v >= target) break;
            else ++ex;
            //cout << "tried " << ex << ' ' << _v << ' ' << _sum <<  endl;
        }
        return ans;
    }
};
