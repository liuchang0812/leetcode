#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
         vector<int> r1;
        vector<int> r2;
        vector<int> r3;

   vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        ret.resize(k);
        // 8 7 3 6 8 
        for (int i=0; i<=min(k, (int)nums1.size()); ++i)
            for (int j=0; j<=min(k, (int)nums2.size()); ++j)
            {
                if (i+j!=k) continue;
                maxNumWithKbit(nums1, i, r1);
                //for (auto i: r1) cout << i; cout << endl;
                maxNumWithKbit(nums2, j, r2);
                //for (auto i: r2) cout << i; cout << endl;
                mergeTwoArray(r1, r2, r3);
                //for (auto i: r3) cout << i; cout << endl;
                if (cmp(r3, ret))
                    ret = r3;
            }
        return ret;
    }

    bool cmp(const vector<int>& nums1, const vector<int>& nums2)
    {
        if (nums1.size() == 0) return false;
        if (nums2.size() == 0) return true;
        for (int i=0; i<min(nums1.size(), nums2.size()); ++i)
        {
            if (nums1[i] > nums2[i]) return true;
            else if (nums1[i] < nums2[i]) return false;
        }

        return false;
    }

    bool cmp2(const vector<int>& nums1, int p, const vector<int>& nums2, int q)
    {
        if (nums1.size() == 0) return false;
        if (nums2.size() == 0) return true;
        for (int i=0; i<min(nums1.size() - p, nums2.size()-q); ++i)
        {
            if (nums1[i+p] > nums2[i+q]) return true;
            else if (nums1[i+p] < nums2[i+q]) return false;
        }

        return nums1.size() - p >= nums2.size() - q;
    }
    void maxNumWithKbit(const vector<int>& nums, int k, vector<int>& ret)
    {
        ret.clear();
        // 8 7 3 6 8
        if (k == 0) return ;
        ret.resize(k);

        int count = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            while (count > 0 && nums[i] > ret[count-1] && nums.size() - i - 1 + count >= k)
                count --;

            if (count < k){
                ret[count] = nums[i];
                count ++;
            } 
        }
        return ;
    }

    void mergeTwoArray(const vector<int>& nums1, const vector<int>& nums2, vector<int>& ret)
    {
        int p = 0;
        int q = 0;


        ret.clear();
       

        while ( p < nums1.size() || q < nums2.size())
        {
            if (p == nums1.size()) 
                ret.push_back(nums2[q++]);

            else if (q == nums2.size())
                ret.push_back(nums1[p++]);
            else
            {
               if (nums1[p] > nums2[q])
                   ret.push_back(nums1[p++]);
               else if (nums1[p] < nums2[q])
                   ret.push_back(nums2[q++]);
               else 
               {
                    bool pre = cmp2(nums1,p , nums2, q);
                    if (pre)
                        ret.push_back(nums1[p++]);
                    else ret.push_back(nums2[q++]);
               }
            }
        }

        return;
    }
};

