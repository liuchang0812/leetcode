#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void WiggleSort(vector<int>& nums)
    {
        vector<int> dummy(nums);
        sort(dummy.begin(), dummy.end());

        for (size_t i=0; i<nums.size(); i++)
        {
            static int len = nums.size();
            if (i&1)
            {
                nums[i] = dummy[len/2 + i/2];
            }
            else
            {
                nums[i] = dummy[i>>1];
            }
        }
    }
};
