#include <iostream>
#include <vector>
#include <string>
using namespace std;

char hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
class Solution {
public:
    string toHex(int num) {
        string ans;
        vector<int> binary;
	for (int i=31; i>=0; --i)
          binary.push_back((num&(1u<<i))!=0);

        for (int i=0; i<32; i+=4) 
        {
          int tmp = binary[i] * 8 + binary[i+1] * 4 + binary[i+2] * 2 + binary[i+3];
          ans += hex_chars[tmp];
        }
        int pos = 0;
        while (ans[pos] == '0') ++ pos;
        return ans.substr(pos) == ""?"0":ans.substr(pos);
    }
};

int main() {
  int n;
  cin >> n;
  Solution sol;
  cout << sol.toHex(n) << endl;
  return 0;
}
