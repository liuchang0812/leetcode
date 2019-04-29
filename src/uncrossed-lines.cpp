#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int dp[505][505];       
        memset(dp, 0, sizeof dp);
        int ans = 0;
        for (int i=0; i<A.size(); ++i) 
            for (int j=0; j<B.size(); ++j)
            {
                int tmp = 0;
                if (A[i] == B[j]) {
                   if (j == 0 || i == 0)
                       tmp = 1;
                   else 
                    tmp = max(tmp, dp[i-1][j-1]+1); 
                } else {
                    
                    if (i!=0)
                        tmp = max(tmp, dp[i-1][j]);

                    if (j!=0)
                        tmp = max(tmp, dp[i][j-1]);
                }
                dp[i][j] = tmp;
                ans = max(ans, dp[i][j]);
            }

        return ans;
    }
};

int main() {
    vector<int> A = {1,4,2};
    vector<int> B = {1,2,4};
    Solution sol;
    cout << sol.maxUncrossedLines(A, B) << endl;
    return 0;
}
