#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        ans.resize(numRows);
        for (int row = 0; row < numRows; row++)
        {
            ans[row].resize(row+1);
            for (int col = 0; col < row + 1; col ++)
            {
                int left, right;
                if ( row-1 < 0) { ans[row][col] = 1; continue;}
                if ( col - 1 < 0) left = 0; else left = ans[row-1][col-1];
                if ( col ==row ) right=0; else right = ans[row-1][col];
                ans[row][col] = left + right;
            }
        }
        return ans;
    }
};

void output(vector<vector<int> > nums)
{
	for(size_t i=0;i <nums.size();i ++)
	{
		for (size_t j=0;j <nums[i].size();j++)
			cout << nums[i][j] << ' ' ;
		cout << endl;
	}
}
int main()
{
	Solution s;
	vector<vector<int> > ans;
	ans = s.generate(10);
	output(ans);
	return 0;
}
