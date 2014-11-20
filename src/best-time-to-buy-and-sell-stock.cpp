class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int len = prices.size();
        int mins[len+1], maxs[len+1];
        mins[0] = maxs[0] = prices[0];
        for (int i=1; i<len; i++)
        {
            mins[i] = min(mins[i-1], prices[i]);
            maxs[i] = max(maxs[i-1], prices[i]);
        }
        int ans = 0;
        for (int i=1; i<len; i++)
        {
            ans = max(ans, prices[i] -mins[i-1]);
        }
        return ans;
    }
};
