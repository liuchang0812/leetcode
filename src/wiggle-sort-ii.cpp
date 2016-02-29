class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> dummy(nums);
        sort(dummy.begin(), dummy.end());
        int len = (nums.size() + 1) / 2;
        
        for (int i=0; i<len; ++i)
            nums[i*2] = dummy[len - i - 1];
        
        for (int i=0; i<nums.size() - len; ++i)
        {
            nums[i*2 + 1] = dummy[nums.size() - i - 1];
        }
    }
};
