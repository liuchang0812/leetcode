#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool SameChar(const vector<string> &strs, int index)
    {
        if (strs.size() == 0) return false;
        for (int i = 0;i < strs.size();i ++)
            if(strs[i].size() < index + 1)
                return false;
        char c = strs[0][index];
        for (int i = 1;i < strs.size();i ++)
        {
            if (strs[i][index] != c) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string> &strs) {
        int maxPrefixLen = 0;
        string maxPrefix;
        for(;;)
        {
            if (SameChar(strs, maxPrefixLen))
            {
                maxPrefix += strs[0][maxPrefixLen];
                maxPrefixLen ++;
            }
            else
            {
                break;
            }
        }
        return maxPrefix;
    }
};
int main()
{
	vector<string> strs;
	strs.push_back("abca");
	strs.push_back("abc");
	Solution s;
	cout << s.longestCommonPrefix(strs);
	return 0;
}
