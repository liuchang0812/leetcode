/*
 * find-mininum-in-rotated-sorted-array-ii.cpp
 * Copyright (C) 2014 liuchang <liuchang@liuchang-pc>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
    int findMin(vector<int> &num) {
        int len = num.size();
        if (len == 0) return -1;
        int l =0, r =len-1;
        int m;
        int ans = num[0];
        while(r > l + 1){
        //    cout <<l << ' ' << r << endl;
            m = l + (r-l)/2;
            if (num[l] < num[m])
            {
                ans = min(num[l], ans);
               l = m + 1; 
            }
            else if (num[l] > num[m]) 
            {
                ans = min(num[l], ans);
               r = m;
            }
            else {
                l++;
            }
        }
        return min(ans,min(num[l], num[r]));
}
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    /*
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    */
    nums.push_back(3);
    cout << "ans "<<s.findMin(nums) <<endl;
    return 0;
}
