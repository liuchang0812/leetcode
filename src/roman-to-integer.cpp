#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
   int romanToInt(string s) {
	   int ans = 0, pre, cur;
	   if (s.empty()) return 0;
	   pre = ans = ToInt(s[0]);	
	   for(size_t i=1;i < s.size();i ++)
	   {
		   cur = ToInt(s[i]);
		   if (cur <= pre)
			   ans += cur;
		   else
			   ans += cur - 2*pre;
		   pre = cur;
	   }
	   return ans;
   }
private:
   int ToInt(char c) {
	   switch(c) {
		case 'I': return 1;
		case 'V': return 5;
	        case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:
			  return -1;
	   }
   }
};

int main(){
	Solution s;
	cout << s.romanToInt("III")<<endl;
	cout << s.romanToInt("IV")<<endl;
	cout << s.romanToInt("C")<<endl;
	cout << s.romanToInt("MCM")<<endl;
	cout << s.romanToInt("MCMLXXXIV") << " == " << 1984<<endl;
	return 0;
}
