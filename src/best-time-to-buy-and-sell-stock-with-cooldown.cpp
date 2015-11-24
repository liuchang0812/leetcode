class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int f[len];
        memset(f, 0, sizeof f);
        f[0] = 0;
        f[1] = max(0, prices[1] - prices[0]);
        for (int j = 2; j < len; j++)
        {
            f[j] = max(max(f[j-1], prices[j] - prices[0]), prices[j] - prices[1]);
            for (int k = 0; k+2 < j; k ++)
                f[j] = max(f[j], f[k] + max(0, prices[j] - prices[k+2]));
        }
        return f[len-1];
    }
};
