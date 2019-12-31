/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> next;
        for (int i=0;i <nums2.size(); ++i) {
            int tmp = -1;
            for (int j=i+1; j<nums2.size(); ++j) {
                if (nums2[j] > nums2[i]) {
                    tmp = nums2[j];
                    break;  
                }
            }
            next[nums2[i]] = tmp;
        }
        vector<int> ans;
        for (auto i:nums1){
            ans.push_back(next[i]);
        }
        return ans;
    }
};
// @lc code=end
