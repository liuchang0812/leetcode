class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        set<int> uniq_nums;
	for (auto i:nums) uniq_nums.insert(i);
        
        map<int, int> cnt;
        for (auto i:nums) ++cnt[i];
        
        int maxLen = 0;
        for (auto i:uniq_nums) maxLen = max(maxLen, cnt[i]);
        
        int ans = INT_MAX;
        for (auto i:uniq_nums) {
	    if (cnt[i] == maxLen) {
                int bg =0; int ed=nums.size()-1;
                while (nums[bg] != i) ++bg;
                while (nums[ed] != i) --ed;
                ans = min(ans, ed-bg+1);
            }
        }
        return ans;
    }
};
