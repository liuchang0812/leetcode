class Solution {
public:
    bool canJump(int A[], int n) {
        if (n < 2) return true;
        int Ok[30000] = {0};
        Ok[0] = A[0];
        for (int i = 1;i < n;i ++)
        {
            if (i > Ok[i-1]) return false;
            Ok[i] = max(Ok[i-1], A[i] + i);
            if (Ok[i] >= n-1) return true;
        }
        return false;
    }
};
