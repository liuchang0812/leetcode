class Solution {
public:
    int rob(vector<int> &num) {
        size_t len = num.size();
        long long ans[len+5][2];
        memset(ans, 0, sizeof ans);
        if (num.size() == 0) 
            return 0;
        ans[0][0] = 0;
        ans[0][1] = num[0];
        for (size_t i=1; i<len; i++)
        {
            ans[i][0] = max(ans[i-1][1], ans[i-1][0]);
            ans[i][1] = ans[i-1][0] + num[i];
        }
        return max(ans[len-1][0], ans[len-1][1]);
    }
};
