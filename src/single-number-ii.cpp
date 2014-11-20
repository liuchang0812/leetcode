class Solution {
public:
    int singleNumber(int A[], int n) {
        int Cnt[32];
        memset(Cnt, 0, sizeof Cnt);
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<32; ++j)
            {
                if ((A[i] >> j)&1)Cnt[j]++;
            }
        }
        int ans = 0, base = 1;
        for (int i=0; i<32; ++i)
        {
            ans += Cnt[i]%3 * base;
            base *= 2;
        }
        return ans;
    }
};
