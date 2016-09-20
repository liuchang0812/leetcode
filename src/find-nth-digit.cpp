#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
    public:
        int nth(int x, int y)
        {
            if (x == 0) return 0;
            vector<int> v;
            while (x)
            {
                v.push_back(x%10);
                x/=10;
            }
            return v[v.size()-y];
        }

        int findNthDigit(int n)
        {
            if (n < 10) return n;
            else
            {
                long long cur = 0;
                int i;
                for (i=1;; ++i)
                {
                    if (i==1)
                        cur = 9;
                    else
                        cur += 9*pow(10, i-1)*i;
                    if (cur >= n)
                        break;
                }
                
                int pre = cur - 9*pow(10, i-1)*i;
                int st = (n - pre) / i;
                int mod = (n - pre) % i;
                cout <<"pre: " << pre << " bytes " << i << ' ' << st << ' ' << mod << endl;
                if (mod == 0)
                {
                    return int((pow(10, i-1) + st - 1)) % 10;
                }
                else
                {
                    int t = (pow(10, i-1) + st);
                    cout << "number is " << t << endl;
                    return nth(t, mod);
                }
            }
        }
};

int main()
{
    Solution sol;
    int n;
    while (cin >> n)
    {
        cout << sol.findNthDigit(n) << endl;
    }
    return 0;
}
