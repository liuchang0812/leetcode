#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
	int countChar(const string& s, char c)
    {
        int ans = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == c) ++ans;
        return ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
                
        int f[105][105];
	int cnt0[605];
	int cnt1[605];

	for (int i=0; i<strs.size(); ++i)
	{
	  cnt0[i] = countChar(strs[i], '0');
	  cnt1[i] = countChar(strs[i], '1');
	}

	cout << "zero one count ok" << endl;

        memset(f, 0, sizeof f);

	for (int i=0; i<strs.size(); ++i)
	{
	  // for (int j=0; j<=m; ++j)
	  for (int j=m; j>=0; --j)
	  {
	    // for (int k=0; k<=n; ++k)
	    for (int k=n; k>=0; --k)
	    {
	      int maxv = 0;
	      // yao
	      if (j >= cnt0[i] && k >= cnt1[i])
	      {
		maxv = f[j-cnt0[i]][k-cnt1[i]] + 1; 
	      }
	      f[j][k] = max(maxv, f[j][k]);
	    }
	  }
	}
	return f[m][n];
    }
};

int main()
{

  Solution sol;
  vector<string> vs;
  int i;
  cin >> i;
  while (i--)
  {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  int m,n;
  cin >> m >> n;
  cout << "read ok" << endl;
  cout << sol.findMaxForm(vs, m, n) << endl;
  return 0;
}
