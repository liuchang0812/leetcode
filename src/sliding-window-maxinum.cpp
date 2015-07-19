#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxValueIndex;
        vector<int> ans;

        for (size_t i=0; i<k; i++)
        {
            while (!maxValueIndex.empty() && nums[*maxValueIndex.rbegin()] <= nums[i])
                maxValueIndex.pop_back();

            maxValueIndex.push_back(i);
        }
        ans.push_back(nums[maxValueIndex[0]]);
        for (size_t i=k; i <nums.size(); ++i)
        {
            if (*maxValueIndex.begin() <= i-k)
                maxValueIndex.pop_front();
            while (!maxValueIndex.empty() && nums[*maxValueIndex.rbegin()] <= nums[i])
                maxValueIndex.pop_back();
            maxValueIndex.push_back(i);
            ans.push_back(nums[maxValueIndex.front()]);
        }
        for (auto i:ans)
        {
            cout << i << endl;
        }
        return ans;
    }
};


int main()
{
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(3);
    vi.push_back(-1);
    vi.push_back(-3);
    vi.push_back(5);
    vi.push_back(3);
    vi.push_back(6);
    vi.push_back(7);
    Solution().maxSlidingWindow(vi, 3);
    return 0;
}
