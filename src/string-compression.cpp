#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string int2str(int x) {
      string ans;
      while (x != 0) {
	ans = char(x%10 + '0') + ans;
	x /= 10;
      }
      return ans;
    }
    int compress(vector<char>& chars) {
      vector<char> ansc;
      vector<int> ansi;
      int ch = chars[0];
      int num = 1;
      for (int i=1;i <chars.size(); ++i) {
	if (chars[i] != ch) {
	  ansc.push_back(ch);
	  ansi.push_back(num);
	  ch = chars[i];
	  num = 1;
	} else {
	  ++num;
	}
      }
      ansc.push_back(ch);
      ansi.push_back(num);
      vector<char> chars_ans;
      for (int i=0; i<ansc.size(); ++i) {
	if (ansi[i] == 1) chars_ans.push_back(ansc[i]);
	else {
	  chars_ans.push_back(ansc[i]);
	  string tmp = int2str(ansi[i]);
	  for (int j=0; j<tmp.size(); ++j)
	    chars_ans.push_back(tmp[j]);
	}
      }
       chars = chars_ans;
      return chars_ans.size();
    }
};

int main () {
  Solution sol;
  vector<char> in = {'a', 'a', 'b', 'b', 'b','c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c','c'};
  cout << sol.compress(in);
  for (auto i:in) cout << i << ' '; cout<< endl;
  return 0;
}
