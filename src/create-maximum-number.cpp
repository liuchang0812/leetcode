#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int f[len1+5][len2+5][k+5];
        memset(f, 0, sizeof f);
        
       for (int kk=1; kk<=k; ++kk)
           for (int i=0; i<len1; ++i)
               for (int j=0; j<len2; ++j)
               {
                
                   int tmp = 0;
                   if (i>0)
                   {
                        tmp = max(tmp, f[kk][i-1][j]);
                        tmp = max(tmp, f[kk-1][i-1][j] * 10 + nums1[i]);
                   }
                   else if(kk==1)
                   {
                       tmp = max(tmp, nums1[i]);
                   }

                   if (j>0)
                   {
                        tmp = max(tmp, f[kk-1][i][j-1] * 10 + nums2[j]);
                        tmp = max(tmp, f[kk][i][j-1]);
                   }
                   else if(kk==1)
                   {
                       tmp = max(tmp, nums2[i]);
                   }

                   cerr <<"k i j " << kk << ' ' << i << ' ' << j << ' ' << tmp << endl;
                   f[kk][i][j] = tmp;
               }
       return f[k][len1-1][len2-1];
    }
};

int main()
{

    vector<int> nums1;
    vector<int> nums2;

    //nums1.push_back(3);nums1.push_back(4); nums1.push_back(6);  nums1.push_back(5);

    //nums2.push_back(9); nums2.push_back(1); nums2.push_back(2); nums2.push_back(5); nums2.push_back(8); nums2.push_back(3);
    //
    nums1.push_back(3); nums1.push_back(9);
    nums2.push_back(8); nums2.push_back(9);

    cout << Solution().maxNumber(nums1, nums2, 3) << endl;
    return 0;
}
