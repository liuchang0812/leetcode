#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
		if (k >= num.size())
			return "0";
        int len = num.size();

        string dummy = num + ' ';

        for (int i=0; i<k; ++i)
        {
            for (int j=0; j<len; ++j)
                if (dummy[j] > dummy[j+1])
                {
                    cout << dummy.substr(0, j) << ' ' << dummy.substr(j+1) << endl;
                    dummy = dummy.substr(0, j) + dummy.substr(j+1);

                    break;
                }
        } 
        int i=0;
        while (i<dummy.size() && dummy[i]=='0') ++i;
        string ans=dummy.substr(i, dummy.size()-1-i);
        if (ans.empty())
            return "0";
        else
            return ans;
    }
};

int main()
{
    Solution sol;

    string s;
    int n;
    while( cin>>s>>n)
    {
        cout << sol.removeKdigits(s, n) << endl;
    }
    return 0;
}
