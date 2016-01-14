#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> get_next(vector<int>& nums)
    {
        int i;
        for(i=nums.size()-1; i>0; --i)
        {
            if(nums[i-1] < nums[i]) break;
        }

        if (i==0) return nums;

        return nums;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        nums.size();
        
        vector<vector<int> > ans;
        return ans;
    }
};
