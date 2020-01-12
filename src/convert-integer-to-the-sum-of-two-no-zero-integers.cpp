class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0;
        int jz = 1;
        while (n > 0) {
            int x = n % 10;
            if (n < 10) {
                if (b == 0) {
                    a = jz+a;
                    b = (n-1)*jz+b;
                } else {
                 
                a = n*jz + a;   
                }
                break;
            }
            if (x == 0) {
                a = 4*jz + a;
                b = 6*jz + b;
                n = n/10 -1;
            } else if (x == 1) {
                a = 2*jz + a;
                b = 9*jz + b;
                n = n/10 - 1;
            } else {
                a = 1 * jz + a;
                b = (x - 1) * jz + b;
                n = n / 10;
            }
            jz *= 10;
        }
        vector<int> ans = {a, b};
        return ans;
    }
};
