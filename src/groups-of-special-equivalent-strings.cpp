#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int f[1000][52];
        memset(f, 0, sizeof f);

        for (int i=0; i<A.size(); ++i) {
            for (int j=0; j<A[i].size(); ++j) {
                if (j%2)
                    ++ f[i][A[i][j] - 'a'];
                else
                    ++ f[i][A[i][j] - 'a' + 26];
            }
        }
        bool eq[1000][1000];
        memset(eq, 0, sizeof eq);

        for (int i=0; i<A.size(); ++i)
            for (int j=i+1; j<A.size(); ++j) {
                bool eq_ = true;
                for (int k=0; k<52; ++k)
                    if (f[i][k] != f[j][k]) {
                        eq_ = false;
                        //cout << "debug: " << i << ' ' << j << ' ' << k << endl;
                        break;
                    }
                eq[i][j] = eq_;
            }

        bool visited[1000];
        int ans = 0;
        memset(visited, 0, sizeof visited);
                for (int i=0; i<A.size(); ++i)
        {
            if (!visited[i]) {
                ++ ans;

                visited[i] = true;
                for (int j=i+1; j<A.size(); ++j)
                    if (eq[i][j])
                        visited[j] = true;
            }
        }
        return ans;
    }
};
