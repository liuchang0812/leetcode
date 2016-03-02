#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int numWidth(long long n)
    {
        int ans =  1;
        long long cur = 10;
        while (n >= cur)
        {
            ans ++;
            cur *= 10;
        }
        return ans;
    }

    bool isAdditiveNumber(string num) {
        int len = num.size();
        long long f[len][len];  // num{i..j}

        for (size_t i=0; i<len; ++i)
            f[i][i] = num[i] - '0';

        for (size_t k=2; k<=len; ++k)
            for (size_t i=0; i+k-1 < len; ++i)
            {
                int j=i+k-1;
                f[i][j] = f[i][j-1] * 10 + f[j][j];
            }

        for (int i=1; i<=len/2; ++i)
            for (int j=1; j<=len/2; ++j)
            {
                if (max(i,j) > len/2) continue;
                long long a = f[0][i-1];
                long long b = f[i][i+j-1];
                int pos = i+j;

                if (a!=0 && num[0] == '0') continue;
                if (b!=0 && num[i] == '0') continue;

                int flag = false;
                while (pos < len)
                {
                    flag = true;
                    cerr <<"a b pos: " <<  a << ' ' << b << ' ' << pos << endl;
                    long long c = a + b;
                    int d = numWidth(c);
                    cout << "c width " << c << ' '  << d << endl;

                    if (pos+d-1 >= len) break;
                    long long c2 = f[pos][pos+d-1];
                    cerr << "c1  c2 " << c << ' ' << c2 << endl;
                    if (c2 == c)
                    {
                        a = b;
                        b = f[pos][pos+d-1];
                        pos = pos+d;
                    }
                    else
                        break;
                }
                if (pos == len && flag) return true;
            }

        return false;
    }
};

int main()
{

    string inp;

    while (cin >> inp)
    {
        cout << Solution().isAdditiveNumber(inp) << endl;
    }
    return 0;
}
