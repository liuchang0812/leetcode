#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
		int ans = 0;        
		int cnt = nums.size();
        if (cnt <= 1) return 0;
        int cnt1[32];

        for (int i=0; i<32; ++i)
        {
            int tmp = 0;
            for (int j=0; j<nums.size(); ++j)
            {
                if (nums[j] & (1<<i))
                    tmp ++;
            }
            cnt1[i] = tmp;
        }
        for (int i=0; i<32; ++i)
            ans += cnt1[i] * (cnt-cnt1[i]);
        return ans;
    }
};

int main()
{
    int n;
    vector<int> vi;
    Solution sol;

    cin >> n;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        vi.push_back(tmp);
    }
    cout << sol.totalHammingDistance(vi) << endl;
    return 0;
}
