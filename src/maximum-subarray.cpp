class Solution {
public:
    int maxSubArray(int A[], int n) {
        int allNeg = true;
        for (int i=0; i<n; ++i)
            if (A[i] >= 0) allNeg=false;
        if (allNeg)
        {
            int ans = -(INT_MAX-1);
            for (int i = 0;i < n;i ++)
                ans = max(ans, A[i]);
            return ans;
        }
        vector<int> f;
        f.resize(n+1);
        f.push_back(0);
        for (int i = 0;i < n; ++i )
        {
            if (f[i] + A[i] < 0)
                f[i+1] = 0;
            else
                f[i+1] = f[i] + A[i];
        }
        int ans = 0;
        for (int i = 0;i <= n;i ++)
            ans = max(ans, f[i]);
        return ans;
    }
};
