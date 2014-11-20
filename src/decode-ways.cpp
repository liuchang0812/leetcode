#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool valid(string s, int i)
    {
        if (i < 0) return false;
        if (s[i] == '1') return true;
        if (s[i] == '2' && s[i+1] <= '6' && s[i] >= '0') return true;
        return false;
    }
    int numDecodings(string s) {
        int len ;
        vector<int> f;
        len = s.size();
        if (s.size() == 0) return 0;
        f.push_back(1);
        for(int i=0; i<len; ++i)
        {
            int tmp = 0;
            if (s[i] != '0')
                tmp += f[i];
            if (valid(s, i-1))
                tmp += f[i-1];
            f.push_back(tmp);
        	
		}
		
        return f[f.size()-1];
    }
};

int main()
{
	Solution s;
	cout << s.numDecodings("1") << endl;
	return 0;
}
