class Solution {
public:
    bool isPrime(int x) {
        static int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (auto i: primes) 
            if (x == i) return true;
        return false;
    }
    bool isPrimeSetNum(int x) {
        int ret = 0;
        for (int i=0; i<32; ++i) {
           if (((1<<i)&x)) ++ret;
        }
        return isPrime(ret);
    }

    int countPrimeSetBits(int L, int R) {
        int ret = 0;
        for (int i=L; i<=R; ++i) 
            if (isPrimeSetNum(i)) ++ret;
        return ret;
    }
};
