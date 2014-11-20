#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> ivec;
typedef map<int, ivec> PosOfChar;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int occ[256];
        memset(occ, 0,sizeof occ);
        int max_ = 0, counter = 0, start = 1;
        for (int i=0; i < s.size(); i++){
            char ch = s[i];
            if (occ[ch] >= start){
                counter -= occ[ch] - start + 1;
                start = occ[ch] + 1;
            }  
            occ[ch] = i+1;
            max_ = max(max_, ++counter);
        }

        return max_;
    }
};
