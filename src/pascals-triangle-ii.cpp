#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
    	ans.resize(rowIndex+1, 0);
        for (int i=0; i<=rowIndex; i++)
        {
            for (int j=i; j>=0; j--)
            {
                if (i-1 < 0) { 
                     ans[j] = 1; continue;
                }
                if (j-1 < 0) continue;
                ans[j] = ans[j-1] + ans[j];
            }
        }
        return ans;
	}
};

int main(){
    Solution s;
    vector<int> ans;
    ans = s.getRow(4);
    for(size_t i=0; i<ans.size(); i++)
        cout << ans[i] << ' ' ; cout << endl;
    return 0;
}
