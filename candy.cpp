#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        size_t len = ratings.size();
        vector<int> incSeq, desSeq;                       
        incSeq.resize(len);
        desSeq.resize(len);
        for (size_t i = 0; i < len; i++)
        {
            incSeq[i] = 1;
            if ( i > 0 && ratings[i-1] < ratings[i])
                incSeq[i] = incSeq[i-1] + 1;
        }
        for (int i=len-1; i >= 0; i--)
        {
            desSeq[i] = 1;
            if ( i < int(len-1) && ratings[i+1] < ratings[i])
                desSeq[i] = desSeq[i+1] + 1;
        }
        int ans = 0;
        for (size_t i=0; i<len; i++)
        {
            ans += max(incSeq[i], desSeq[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> ratings;
    ratings.push_back(0);
    ratings.push_back(0);
    ratings.push_back(2);
    Solution s;
    cout << s.candy(ratings) << endl;
    return 0;
}
