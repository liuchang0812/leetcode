class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      
        map<int, int> cnt;
        for (size_t i = 0; i < min(int(nums.size()), k+1); ++i)
        {
            cnt[nums[i]] ++;
            if (cnt[nums[i]] > 1) return true;
            
        }
        for (size_t i = k+1; i < nums.size(); ++i)
        {
            int pre = i - k - 1;
            cnt[nums[pre]] --;
            cnt[nums[i]] ++;
            if (cnt[nums[i]] > 1) return true;
        }
        return false;
    }
};
