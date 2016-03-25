#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.resize(num + 1);

        for (int i=0; i<=num; ++i)
        {
            int p = (i<<1);
            if (p <= num) ret[p] = ret[i];
            p = (i<<1) + 1;
            if (p <= num) ret[p] = ret[i] + 1;
        }

        return ret;
    }
};


int main()
{

    int n;
    cin >> n;
    auto ret = Solution().countBits(n);
    for (auto i:ret)
        cout << i << endl;
    return 0;
}
