#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool equal(int x, double f)
{
    static double eps = 1e-10;
    
    return fabs(f-x) <= eps;
}

bool isPowerOfThree(int n) {
    if (n<=0) return false;
    double ret = log(n) / log(3);
    return equal(floor(ret), ret) || equal(ceil(ret), ret);
}

int main()
{
    printf("243 %d\n", isPowerOfThree(243));
    printf("242 %d\n", isPowerOfThree(242));
    return 0;
}
