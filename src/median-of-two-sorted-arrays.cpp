#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
   public:
        int findkth(int A[], int m, int B[], int n, int k) {
            if (m > n)
                return findkth(B, n, A, m, k);
            if (m == 0)
                return B[k-1];
            if (k == 1)
                return min(A[0], B[0]);

            int pos_A = min(k/2, m);
            int pos_B = k - pos_A;
            if (A[pos_A-1] < B[pos_B-1])
                return findkth(A + pos_A, m - pos_A, B, n, k-pos_A);
            else if (A[pos_A-1] > B[pos_B-1])
                return findkth(A, m, B+pos_B, n-pos_B, k-pos_B);
            else
                return A[pos_A-1];
        }

        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            if ( (m+n) & 1)
            {
                cout << findkth(A, m, B, n, ((m+n)>>1) + 1) << endl;
                return findkth(A, m, B, n, ((m+n)>>1) + 1);
            }
            else
            {
                cout << findkth(A, m, B, n, ((m+n)>>1) + 1) << endl;
                cout << findkth(A, m, B, n, (m+n)>>1) << endl;
                return (findkth(A, m, B, n, ((m+n)>>1) + 1) + 
                        findkth(A, m, B, n, (m+n)>>1)) / 2.0;
            }
        }
};

int main() {
//int A[] = {1,1,2,4,5,7,7};
//    int B[] = {2,5,5,5};
    int A[] = {};
    int B[] = {2,3};
    Solution s;
    cout << s.findMedianSortedArrays(A, 0, B, 2) << endl;
    return 0;
}

