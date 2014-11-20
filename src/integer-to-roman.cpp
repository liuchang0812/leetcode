#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            init();
            string ans;
            for (int i=0; ;i++)
            {
                int val = num % 10;
                num /= 10;
                ans = Gen(val, i) + ans;
                if (num <= 0) break;
            }
            return ans;
        }
    private:
        string Gen(int val, int base) {
            switch(val){
                case 0: return "";
                case 1: return Tags[base*2 + 0]; 
                case 2: return Tags[base*2 + 0] + Tags[base*2 + 0] ;
                case 3: return Tags[base*2 + 0] + Tags[base*2 + 0] + Tags[base*2 + 0];
                case 4: return Tags[base*2 + 0] + Tags[base*2+1];
                case 5: return Tags[base*2 + 1];
                case 6: return Tags[base*2 + 1] + Tags[base*2 + 0];
                case 7: return Tags[base*2 + 1] + Tags[base*2 + 0] + Tags[base*2 + 0];
                case 8: return Tags[base*2 + 1] + Tags[base*2 + 0] + Tags[base*2 + 0]+ Tags[base*2 + 0];
                case 9: return Tags[base*2 + 0] + Tags[base*2 + 2];
            }
        }
        void init() {
            Tags.push_back("I");
            Tags.push_back("V");
            Tags.push_back("X");
            Tags.push_back("L");
            Tags.push_back("C");
            Tags.push_back("D");
            Tags.push_back("M");
        }

        vector<string> Tags;
};


void test()
{
    Solution s;
    for (int i = 0; i< 25; i++)
    {
        cout << i << ' ' << s.IntToRoman(i) << endl;
    }
}

int main()
{
    test();
    return 0;
}


