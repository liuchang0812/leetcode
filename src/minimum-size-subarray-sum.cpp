#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size()==0) return 0;
        vector<long long> accSum;
        accSum.push_back(0);
        for (size_t i=0; i < nums.size(); ++i)
            accSum.push_back(accSum.back() + nums[i]);

        for (size_t len=1; len<=nums.size(); ++len)
        {
            for(size_t i=len; i<=nums.size(); ++i)
                if (accSum[i] -  accSum[i-len] >= s) return len;
        }
        return 0; 
    }
};
