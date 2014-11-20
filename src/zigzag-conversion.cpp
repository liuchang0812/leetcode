#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        vector<string> matrix;
        matrix.resize(nRows);
        int dir = 1, row = 0;
        for (int i = 0;i < s.size(); i ++)
        {
            matrix[row] += s[i];
            if (dir == 1)
            {
                row ++;
                if (row + 1 == nRows)
                    dir = -1;
            }
            else
            {
                row --;
                if (row == 0)
                    dir = 1;
            }
        }
        string ans;
        for (int i =0;i < nRows; i++)
            ans += matrix[i];
        return ans;
    }
};

int main()
{
    Solution s;
    string st;
    st = "PAYPALISHIRING";
    cout << s.convert(st, 3) << endl;
    return 0;
}
