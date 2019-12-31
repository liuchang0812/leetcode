/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int maxV = 0;
        for (int i=1;i <A.size(); ++i) {
            if (A[i] < maxV) return false;

            
            maxV = max(maxV, A[i-1]);
        }
        return true;
    }
};


// f[n] >= f[n-1]  OK
// f[n] < f[n-1] 
// @lc code=end


