#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:

    // maxChoosableInteger <= 20, desiredTotal <= 300
    // 2^20 * 300 = 2^20 * 2^5 = 2^25

    // map<int, int> Memory; // 2 win, 1 lose, 0 unknow now
    int Memory[1048580];

    bool choosable(int i, int tobe)
    {
        if ((1 << i)&(~tobe))
            return true;
        else 
            return false;
    }

    bool dfs(int ToBeChoose, int maxChoosableInteger, int desiredTotal)
    {

        if (Memory[ToBeChoose] != 0) {
            return Memory[ToBeChoose] == 2;
        }

        if (desiredTotal <= 0)
        {
            // cout << ToBeChoose << ' ' << desiredTotal << ' ' << true << endl; 
            Memory[ToBeChoose] = 1;
            return false;
        }

        bool failAnyway = true;
        for (int i=0; i<maxChoosableInteger; ++i)
        {
            if (choosable(i, ToBeChoose))
            {
                int newI = ToBeChoose | (1<<i);
                if (dfs(newI, maxChoosableInteger, desiredTotal - (i+1)))
                {
                    //pass
                }
                else
                {
                    failAnyway = false;
                    break;
                }
            }
        }
        // cout << ToBeChoose << ' ' << maxChoosableInteger << ' ' << desiredTotal << ' '<< "fail anyway " << failAnyway << endl;
        if (failAnyway) {
            Memory[ToBeChoose] = 1;
            return false;
        } else {
            Memory[ToBeChoose] = 2;
            return true;
        }
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true; 
        memset(Memory, 0, sizeof Memory);
        auto sumV = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if (sumV < desiredTotal)
            return true;
        
        return dfs(0, maxChoosableInteger, desiredTotal);
    }
};

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        Solution sol;
        cout << sol.canIWin(n, k) << endl; 
    }
    return 0;
}
