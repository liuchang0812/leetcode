#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string exec_exepress(string tmp)
    {
        vector<char> op;
        vector<int> nums;

        int tmp_num = 0;

        for (size_t i=0; i<tmp.size(); ++i)
            if (tmp[i] <= '9' && tmp[i] >= '0')
                tmp_num = tmp_num * 10 + tmp[i] - '0';
            else
            {
                op.push_back(tmp[i]);
                nums.push_back(tmp_num);
                tmp_num = 0;
            }
        nums.push_back(tmp_num);


        int pre = nums[0];

        for (size_t i=0; i<op.size(); ++i)
        {
            if (op[i] == '-')
                pre = pre - nums[i+1];
            else
                pre = pre + nums[i+1];
        }


        if (pre == 0) return "0";
        else
        {
            string ans;
            while (pre)
            {
                ans = char(pre%10 + '0') + ans;
                pre /= 10;
            }
            return ans;
        }
    }

    int calculate(string s) {
        stack<char> st;        

        string s2 = '(' + s + ')';

        for (auto c:s2)
        {
            if (c == ' ')
                continue;

            if (c == ')')
            {
                string tmp = "";

                while (!st.empty())
                {
                    char c = st.top(); st.pop();
                    if (c == '(')
                        break;
                    tmp = c + tmp;
                }
                string v = exec_exepress(tmp);
                for (size_t i=0; i<v.size(); ++i)
                    st.push(v[i]);

            }
            else
                st.push(c);
        }

        int ans = 0;
        while (!st.empty())
        {
            ans = ans*10 + st.top()-'0';
            st.pop();
        }

        return ans;
    }
};


int main()
{

    string s;
    while ( cin>>s)
    {
        cout << Solution().exec_exepress(s) << endl;
    }
    return 0;
}
