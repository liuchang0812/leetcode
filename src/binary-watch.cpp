#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

class Solution{
public:

    int count(int n)
    {
        int ret = 0;
        for (int i=0; i<6; ++i)
        {
            if ((1<<i)&n)
                ret ++;
        }
        return ret;
    }
    
    string toString(int n, int m)
    {
        stringstream ss;
        if (m < 10)
        {
            ss << n << ":" << 0 << m;
        }
        else 
        {
            ss << n << ":" << m ;
        }
        cout << ss.str() << endl;
        return ss.str();
    }

    vector<string> readBinaryWatch(int n)
    {
        vector<string> ans;
        if (n > 10) return ans;

        for (int h=0; h<12; ++h)
            for (int m=0; m<60; ++m)
            {
                if (count(h) + count(m) == n)
                    ans.push_back(toString(h, m));
            }

        return ans;
    }
};


int main()
{
    Solution sol;
    sol.readBinaryWatch(3);
    return 0;
}
