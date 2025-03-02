class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cnt[32];
        memset(cnt, 0, sizeof cnt);
        auto fGetValue = [&]{
            int v = 0;
            long long b = 1;
            for (int i=0; i<32; ++i) {
                //cout <<cnt[i] << ' ';
                if (cnt[i] > 0) v += b;
                b *= 2;
            }
            //cout <<endl;
            //cout << "get value: " << v << endl;
            return v;
        };

        int bg, ed;
        bg = 0;
        ed = -1;

        int res = INT_MAX;
        while( ed < int(nums.size())) {
            //cout << "=============" << ed << "=====" << endl;
            ++ed;
            if (ed < int(nums.size()))
            {
              for (int i=0;i<32;++i) {
                if (nums[ed]&(1<<i)) ++cnt[i];
              }
            } 
            //cout << "try bg ed: " << bg << ' ' << ed << endl;

            while (fGetValue() >= k) {
                //cout << "bg ed: " << bg << ' ' << ed << endl;

                res = min(res, ed - bg + 1);
                if (bg < ed) {
                    for (int i=0;i<32;++i) {
                        if (nums[bg]&(1<<i)) --cnt[i];
                    }
                    ++bg;
                } else {
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};