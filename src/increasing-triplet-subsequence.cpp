#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        vector<int> qa;
        int qb;
        if (nums.size() < 3) return false;
        
        qb = nums[0];
        qa.push_back(nums[0]);
        int pos = 1;

        while (pos < nums.size())
        {
            int num = nums[pos];

            if (num <= qb)
            {
                if (qa.size() == 1)
                    qa[0] = num;

                qb = num;
            }
            else
            {
                if (qa.size() == 2 && num > qa.back())
                    return true;
                else if (qa.size() == 2 && num <= qa.back() && num > qa.front())
                {
                    qa[1] = num;
                }
                else if (qa.size() == 2 && num <= qa[0])
                {
                    qa[0] = qb;
                    qa[1] = num;
                }
                else if (qa.size() == 1 && num > qa[0])
                    qa.push_back(num);
                else if (qa.size() == 1 && num <= qa[0])
                    qa[0] = num;
            }
            pos ++;
        }
        return false;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> inp;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        inp.push_back(tmp);
    }

    cout << Solution().increasingTriplet(inp) << endl;
    return 0;
}
