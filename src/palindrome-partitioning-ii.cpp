#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        // f[i] =  f[k] + 1 if pali(str(k+1, i)) && f[k]!=-1     
        // f[0] = 0
        //
        
        int len = s.size();
        bool pali[len+1][len+1];
        int f[len+1];
        
        for (size_t i=0; i<=len; ++i)
            for (size_t j=0; j<=i; ++j)
                pali[i][j] = true;

        for (int l = 2; l<=len; ++l)
            for (int i=1; i+l-1<=len; ++i)
            {
                int j = i+l-1;

                if (s[i-1] != s[j-1])
                    pali[i][j] = false;
                else
                    pali[i][j] = pali[i+1][j-1];
            }

        f[0] = -1;
        for (size_t i=1; i<=len; ++i)
        {
            f[i] = INT_MAX;
            for (size_t j=1; j<=i; ++j)
            {
                if (pali[j][i] && f[j-1]!=INT_MAX)
                {
                    f[i] = min(f[i], f[j-1] + 1);
                    cout << "update " << j << ' ' << i << ' ' << pali[j][i] << endl;
                }
            }
            cout << i << ' ' << f[i] << endl;
        }
        return f[len];
    }
};


int main()
{
    string s;
    while (cin>>s)
    {
        cout << Solution().minCut(s) <<endl;
    }
    return 0;
}
