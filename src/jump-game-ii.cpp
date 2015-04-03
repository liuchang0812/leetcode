class Solution {
public:
    int jump(int A[], int n) {
        int steps[100005];
        for(int i=0; i<100005; i++) steps[i] = INT_MAX;
        int cur = 0;
        steps[0] = 0;
        
        for (int i=0; i < n-1; i++)
        {
            for (int j = max(i+1, cur+1); j <= min(i+A[i], n-1); j++)
                steps[j] = min(steps[j], steps[i] + 1);
            cur = min(i+A[i], n-1);
            if (cur == n-1) return steps[n-1];
        }
        return steps[n-1];
    }
};
