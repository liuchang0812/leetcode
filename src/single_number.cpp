class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n < 1) return -1;
        int ans = A[0];
        for (int i = 1;i < n;i ++)
            ans ^= A[i];
        return ans;
    }
};
