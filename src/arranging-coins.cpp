class Solution {
public:
    int arrangeCoins(int n) {
            /*
               (1+k) * k / 2 = n
               
               k + k^2 - 2n = 0
               k^2 + k - 2n = 0
               -1 +/- sqrt(1+8n) / 2
              */
              return int((-1 + sqrt(1.0+8.0*n)) / 2);
    }
};
