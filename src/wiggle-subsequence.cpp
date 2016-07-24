class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        
        int dp[len][2]; // dp[i][0]: nums[i+1] > nums[i]
                        // dp[i][1]: nums[i+1] < nums[i]
        memset(dp, 0, sizeof dp);
        
        int ans = 0;
        for (int i=0; i<len; ++i)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
            for (int j=0; j<i; ++j)
            {
                if (nums[i] == nums[j]) continue;
                
                if (nums[i] > nums[j])
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                else
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
    
};
