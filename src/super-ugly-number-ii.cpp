#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNumbers;
        superUglyNumbers.push_back(1);  // first super ugly number
        int numPrimes = primes.size();
        vector<int> idxs(numPrimes, 0);
        // add super ugly number up to nth 
        while(superUglyNumbers.size() < n)
        {
            int nextSuperUglyNumber = superUglyNumbers[idxs[0]]*primes[0];   // next super ugly number
            for(int i = 0; i < numPrimes; i++)
            {
                nextSuperUglyNumber = min(nextSuperUglyNumber, superUglyNumbers[idxs[i]]*primes[i]);
            }
            for(int i = 0; i < numPrimes; i++)
            {
                if(nextSuperUglyNumber == superUglyNumbers[idxs[i]]*primes[i])
                {
                    idxs[i]++;
                }
            }
            superUglyNumbers.push_back(nextSuperUglyNumber);
        }

        return superUglyNumbers[n-1];
    }
};
