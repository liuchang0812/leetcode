#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int getKth(int k, const  vector<bool> nums)
    {
        int cur = 0;
        for (size_t i=1; i<nums.size(); ++i)
        {
            if (nums[i]) cur++;
            if (cur == k) return i;
        }
        return 0;
    }
    
    int numsPermutaion(int n)
    {
        int ans = 1;
        for (int i=1; i<=n; i++) ans*=i;
        return ans;
    }

    string getPermutation(int n, int k) {

    int remain = k-1;
    vector<bool> nums; nums.resize(n+1); fill(nums.begin(), nums.end(), true);
    string ans;


    for (int i=0; i<n; ++i)
    {
        int tmp = n - i - 1;
        int cnt = numsPermutaion(tmp);

        int th = remain / cnt + 1;

        int choose = getKth(th, nums);
        nums[choose] = false;
        ans = ans + char(choose + '0');
        remain %= cnt;
    }

    return ans;
    }
};


int main()
{
    Solution sol;

    int n, k;
    while (cin >> n >> k)
    {
        cout << sol.getPermutation(n, k) << endl;
    }
    return 0;
}
