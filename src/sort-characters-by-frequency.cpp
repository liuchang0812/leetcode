#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        typedef pair<char, int> charCount;
        vector<charCount> charCounts;
        map<char,int> cnt;
        for (auto i:s)
            ++cnt[i];
        for (auto i:cnt)
            charCounts.push_back(make_pair(i.first, i.second));

        sort(charCounts.begin(), charCounts.end(), [](charCount x, charCount y) { return x.second > y.second || (x.second == y.second && x.first < x.first); });
        string ans;
        for (auto i:charCounts) {
            for (int j=0; j<i.second; ++j)
                ans += i.first;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abbeee";
    cout << sol.frequencySort(s) << endl;
    return 0;
}
