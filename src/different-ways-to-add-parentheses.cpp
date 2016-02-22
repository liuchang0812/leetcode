#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        vector<char> op;
        vector<int> nums;

        int tmp_num = 0;
        for (size_t i=0; i<input.size(); ++i)
        {
            if (input[i] <= '9' && input[i] >= '0')
                tmp_num = tmp_num * 10 + input[i] - '0';
            else
            {
                nums.push_back(tmp_num);
                tmp_num = 0;
                op.push_back(input[i]);
            }
        }
        nums.push_back(tmp_num);

        map<pair<int, int>, vector<int> > f;

        for (size_t i=0; i<nums.size(); ++i)
        {
            vector<int> tmp;
            tmp.push_back(nums[i]);
            f[make_pair(i, i)] = tmp;
        }

        for (size_t len=2; len <= nums.size(); ++len)
            for (size_t i=0; i+len-1 < nums.size(); ++i)
            {
                int j=i+len-1;
                vector<int> tmp_ans;

                for (int k=i+1; k<=j; ++k)
                {
                    vector<int> s1;
                    vector<int> s2;
                    s1 = f[make_pair(i, k-1)];
                    s2 = f[make_pair(k, j)];
                    char opchar = op[k-1];


                    for (auto t1:s1)
                        for (auto t2:s2)
                        {
                           if (opchar == '+')
                              tmp_ans.push_back(t1+t2); 
                           else if (opchar == '-')
                               tmp_ans.push_back(t1-t2);
                           else
                               tmp_ans.push_back(t1*t2);
                        }
                }
                f[make_pair(i, j)] = tmp_ans;
            }

        vector<int> ret;
        for (auto i:f[make_pair(0, nums.size()-1)])
        {
            cout << "get one " << i << endl;
            ret.push_back(i);
        }
        return ret;
    }
};

int main()
{
    string s;
    while (cin >> s)
    {
        Solution().diffWaysToCompute(s);
    }
    return 0;
}
