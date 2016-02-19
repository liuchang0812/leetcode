#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class NumArray {
public:
    vector<long long> sums;
    NumArray(vector<int> &nums) {
        if (nums.size()!=0)
        {
            sums.push_back(nums[0]);

            for (size_t i=1; i<nums.size(); ++i)
                sums.push_back(sums.back() + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return sums[j] - (i==0?0:sums[i-1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{

    vector<int> inp;
    for (int i=0; i<5; i++)
        inp.push_back(i);

    NumArray numArray(inp);

    cout << numArray.sumRange(0, 1) << endl;
    cout << numArray.sumRange(1, 2) << endl;

    return 0;
}
