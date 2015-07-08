class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        int ans = 0;
        for (size_t i = 0; i < 32; i ++)
            ans += (n & (1 << i)) != 0;
        return ans == 1;
    }
};
