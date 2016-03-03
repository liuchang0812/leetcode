#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, vector<int> &primes) {
        map<int, bool> exist;

        vector<long long> uglyNumbers; 
        int index=0;
        uglyNumbers.push_back(1);
        exist[1] = true;

        vector<int> factor;


        for (auto i:primes)
        {
            factor.push_back(i);
        }

        while (true)
        {
            if(index == n-1) return uglyNumbers[n-1];
            for (auto i:factor)
            {
                if (exist[i*uglyNumbers[index]]) continue;
                //uglyNumbers.push_back(i*uglyNumbers[index]);
                int j = uglyNumbers.size()-1;
                while (j>=0 && uglyNumbers[j] > i*uglyNumbers[index])
                    j--;
                uglyNumbers.insert(uglyNumbers.begin() + j + 1, i*uglyNumbers[index]);
                exist[i*uglyNumbers[index]] = true;
            }
            index ++;
            //sort(uglyNumbers.begin(), uglyNumbers.end());
        }
        return 1;
    }
};


int main()
{

    vector<int> primes;
    int n;

    int k;

    cin  >> n;
    cin >> k;
    for (int i=0; i<k; ++i)
    {
        int tmp;
        cin >> tmp;
        primes.push_back(tmp);
    }

    cout << Solution().nthUglyNumber(n, primes) << endl;
    return 0;
}
