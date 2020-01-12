class Solution {
public:
    int minFlips(int a, int b, int c) {
        int _c = a | b;
        int ans=0;
        for (int i=0;i<32;++i) {
            int t = 1<<i;
            if ((_c&t) == (c&t)) continue;
            else {
                if ((c&t) == 0) {
                    //cout <<"d1 " << i << ' ' << ans << endl;
                    ans += ((a&t) != 0) + ((b&t) != 0);
                } else {
                    //cout <<"d2 " << i << ' ' << ans << endl;

                    ++ans;
                }
            }
        }
        return ans;
    }
};
