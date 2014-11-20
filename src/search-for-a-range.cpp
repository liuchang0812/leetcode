#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int>::iterator p;
        vector<int> AA;
        for (int i = 0;i < n;i ++)
            AA.push_back(A[i]);
        p  = lower_bound(AA.begin(), AA.end(), target);
        vector<int> ans;
        if (p == AA.end()) ans.push_back(-1); else ans.push_back(p - AA.begin());
        if (A[n-1] == target) ans.push_back(n-1);
        else
        {
            auto q = upper_bound(A, A+n, target);
            if (q == A+n) ans.push_back(-1); else ans.push_back(q - A);
        }
        return ans;
    }
};

int main() {
    Solution s;
    int A[] = {1,2,3,4,5,5,5,5,6};
    s.searchRange(A, 9, 5);
    return 0;
}
