class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        int tmp[k];
        for (int i = 0; i < k; i++)
            tmp[i] = nums[n-k+i];
        for (int i = n-1;i >= k; i--)
            nums[i] = nums[i-k];
        for (int i=0 ; i < k; i++)
            nums[i] = tmp[i];
    }
};
