class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) return 0;
        int n = A.size();
        int ans = INT_MIN;
        int s0 = 0;
        int sum = 0;
        for (int i=0; i<n; ++i)
        {
            s0 += i*A[i];
            sum += A[i];
        }
        ans = s0;
        vector<int> sums;
        sums.push_back(ans);
        for (int i =0; i < n-1; ++i)
        {
            sums.push_back(sums.back() - sum + n*A[i]);
            ans = max(ans, sums.back());
        }
        return ans;
    }
};
