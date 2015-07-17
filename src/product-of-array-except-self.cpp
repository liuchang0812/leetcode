class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (i==0)
                out.push_back(nums[0]);
            else
                out.push_back(nums[i] * out[i-1]);
        }
        
        for (int i = nums.size()-2; i >= 0; i --)
        {
            nums[i] = nums[i] * nums[i+1];
        }
        
        for (int i = nums.size()-1; i >= 0; -- i)
        {
            if (i == 0)
                out[i] = nums[1];
            else if (i == nums.size() - 1)
                out[i] = out[i-1];
            else
                out[i] = out[i-1] * nums[i+1];
        }
        return out;
    }
};
