class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums;
        if (nums.size() == 0) return -1;
        sums.push_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) 
            sums.push_back(sums.back() + nums[i]);

        for (int i=0; i <nums.size(); ++i)
        {
            if (i == 0 && sums.back() - sums[0] == 0) return 0;
            else if (sums[i-1] == sums.back() - sums[i]) return i;
        }
            
        return -1;
    }
};
