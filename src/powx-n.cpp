class Solution {
public:
    double pow2(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double tmp;
        if (n&1)
        {
            tmp = pow2(x, n/2);
            return tmp*tmp*x;
        }
        else 
        {
            tmp = pow(x, n/2);
            return tmp*tmp;
        }
    }
    double pow(double x, int n) {
        double ans = 1;
        int op = n > 0;
        n = abs(n);
        ans = pow2(x, n);
        if (!op) ans = 1 / ans;
        return ans;
    }
};
