#include <vector>
#include <iostream>
using namespace std;

class NumArray {
public:
    int lowbit(int x){
        return x&(-x);
    }

    vector<int> dummy;
    vector<int> sums;
    int N;

    void bt_modify(int p, int delta)
    {
        while(p<=N)
        {
            sums[p] += delta;
            p += lowbit(p);
        }
    }

    int bt_sum(int p)
    {
        int rs = 0;
        while (p)
        {
            rs += sums[p];
            p -= lowbit(p);
        }
        return rs;
    }

    NumArray(vector<int> &nums) {
        dummy = nums;
        sums.resize(nums.size()+1);
        N = nums.size();

        for (int i=0; i<N; ++i)
            bt_modify(i+1, nums[i]);
    }

    void update(int i, int val) {

        int del = val - dummy[i];
        dummy[i] = val;

        bt_modify(i+1, del);
    }

    int sumRange(int i, int j) {
        return bt_sum(j+1) - bt_sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
//
int main()
{
    vector<int> inp;
    inp.push_back(1);
    inp.push_back(1);
    inp.push_back(1);
    inp.push_back(1);
    inp.push_back(1);
    NumArray numArray(inp);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;

    return 0;
}
