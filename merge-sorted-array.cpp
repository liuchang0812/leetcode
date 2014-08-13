class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=0,j=0;
        while (i < m && j < n)
        {
            if (A[i] < B[j]) {
                ++i;continue;
            }
            else {
                m ++;
                for (int k = m-2; k >= i; k--)
                    A[k+1] = A[k];
                A[i] = B[j];
                i++;
                j++;
            }
        }
        while (j < n)
        {
            A[i++] = B[j++];
        }
    }
};
