class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> left, right;
        left.push_back(0);
        for (int i=1; i<A.size(); ++i) {
                if (A[i-1] < A[i])
                        left.push_back(left.back() + 1);
                else
                        left.push_back(0);
        }

        right.push_back(0);
        for (int i=A.size()-2; i>=0; --i) {
                if (A[i] > A[i+1])
                        right.push_back(right.back() + 1);
                else
                        right.push_back(0);
        }
        reverse(right.begin(), right.end());

        int ans = 0;

        for (int i=0; i < A.size(); ++i) {
                if (left[i] + right[i] + 1 > ans && left[i] + right[i] + 1 >= 3 && left[i] > 0 && right[i] > 0) {
                        ans = left[i] + right[i] + 1;
                }
        }
        return ans;
    }
};
