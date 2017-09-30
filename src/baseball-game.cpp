#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
    	auto sum = 0L;       
        stack<int> valid_nums;
        for (auto& i: ops) {
            if (i == "C") {
                int top = valid_nums.top();
                sum -= top;
                valid_nums.pop();
            } else if (i == "D") {
                int top = valid_nums.top();
                sum += top * 2;
                valid_nums.push(top*2);
            } else if (i == "+") {
                int top1 = valid_nums.top(); valid_nums.pop();
                int top2 = valid_nums.top();
                sum += top1 + top2;
                valid_nums.push(top1);
                valid_nums.push(top1+top2);
            } else {
                auto num = atoi(i.c_str());
                sum += num;
                valid_nums.push(num);
            }
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> inputs;
    while (n--) {
        string tmp;
        cin >> tmp;
        inputs.push_back(tmp);
    }

    Solution sol;
    cout << sol.calPoints(inputs) << endl;
}


