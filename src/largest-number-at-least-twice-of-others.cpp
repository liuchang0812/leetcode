class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      map<int, int> pos;
      for (int i=0;i <nums.size(); ++i) pos[nums[i]] = i;
      sort(nums.begin(), nums.end());
      return nums[nums.size()-1] >= 2*nums[nums.size()-2] ? pos[nums[nums.size()-1]] : -1;
    }
};
