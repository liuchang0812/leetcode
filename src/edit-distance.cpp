#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        int f[len1+2][len2+2];
        memset(f, 0, sizeof f);
        for (size_t i=1; i<=word1.size(); ++i)
            f[i][0] = i;
        for (size_t i=1; i<=word2.size(); ++i)
            f[0][i] = i;
        for (size_t i=1; i<= word1.size(); ++i)
            for (size_t j=1; j<=word2.size(); ++j)
            {
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
                //cout << i << ' ' << j << ' ' << f[i][j] << endl;
            }
        
        return f[len1][len2];
    }
};
