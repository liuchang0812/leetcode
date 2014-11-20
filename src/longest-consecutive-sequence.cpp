#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            int maxlen = 0;
            for (size_t i=0; i<num.size(); i++)
                flags.insert(num[i]);

            for (size_t i = 0;i < num.size(); i++)
            {
                int len1 = findMaxLen(num[i], 1);
                int len2 = findMaxLen(num[i]-1, -1);
                maxlen = max(maxlen, len1 + len2);
            }
            return maxlen;
        }
    private:
        unordered_set<int> flags;
        int findMaxLen(int value, int dir)
        {
            int _maxlen = 0;
            while (flags.find(value) != flags.end())
            {
                _maxlen ++;
                flags.erase(value);
                value += dir;
            }
            return _maxlen;
        }
};

int main()
{
    vector<int> num;
    Solution s;
    num.push_back(10);
    num.push_back(9);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    cout <<  s.longestConsecutive(num) << endl;
    return 0;
}

