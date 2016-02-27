#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        // k = len(num) - 1
        // 4 choices: none, plus, minus, multi
        // dfs 4^k 
        string con(const string& num, const vector<int> &cur)
        {
            string ret;
            ret = num[0];

            for (int i=0; i<cur.size(); ++i)
            {
                switch(cur[i])
                {
                    case 0:
                        break;
                    case 1:
                        ret += '+';
                        break;
                    case 2:
                        ret += '-';
                        break;
                    case 3:
                        ret += '*';
                        break;
                }
                ret += num[i+1];
            }
            return ret;
        }

        bool valid(string tmp, int target)
        {
            bool ret = true;
            stack<char> ops;
            stack<int> operands;

            int pre = 0;
            for (size_t i=0; i<tmp.size(); ++i)
            {
                if (tmp[i] <= '9' && tmp[i] >= '0')
                {
                    pre = pre * 10 + tmp[i] - '0';
                }
                else
                {
                    while (!ops.empty() && (ops.top() == '*' || ((tmp[i] == '+' || tmp[i] == '-') && (ops.top() == '+' || ops.top() == '-'))))
                    {
                        char op = ops.top(); ops.pop();
                        int n = operands.top(); operands.pop();
                        if (op == '*') pre *= n;
                        else if(op == '+') pre += n;
                        else if(op == '-') pre = n - pre;
                    }
                    operands.push(pre);
                    pre = 0;
                    ops.push(tmp[i]);
                }

            }

            operands.push(pre);

                while (!ops.empty())
                {
                    char op = ops.top(); ops.pop();
                    int s2 = operands.top();  operands.pop();
                    int s1 = operands.top();  operands.pop();
                    // operands.push(s1 op s2);
                    if (op == '*') operands.push(s1 * s2);
                    else if (op == '+') operands.push(s1 + s2);
                    else operands.push(s1 - s2);
                }
                return operands.top() == target;
        }

        void dfs(int cur_st, int tot_st, const string& num, int target, vector<int> &cur, vector<string> &ans)
        {
            if (cur_st == tot_st)
            {
                string tmp = con(num, cur);
                if (valid(tmp, target))
                {
                    ans.push_back(tmp);
                }
            }
            else
            {
                for (int i=0; i<4; i++)
                {
                    cur[cur_st] = i;
                    dfs(cur_st + 1, tot_st, num, target, cur, ans);
                }
            }
        }

        vector<string> addOperators(string num, int target)
        {
            vector<string> ans;
            int k = num.size() -1;
            vector<int> cur(k);
            dfs(0, k, num, target, cur, ans);
            return ans;
        }
};


int main()
{

    string num;
    int target;
    while(cin >> num >> target)
    {
        vector<string> ans;
        ans = Solution().addOperators(num, target);
        for (auto i:ans)
            cout << i << endl;
    }
    return 0;
}
