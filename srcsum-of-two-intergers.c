
int getSum(int na, int nb)
{
    int a,b;
    int c = 0;
    int v;
    int ans = 0;
    int base = 1;

    for (int i=0; i<32; ++i)
    {   
        a = ((na & (1<<i)) != 0);
        b = ((nb & (1<<i)) != 0);
        v = a^b^c;
        c = ((a|b)&c) | ((a|c)&b) | ((b|c)&a);

        ans = v * base + ans;
        printf(" ans %d, a %d, b %d,v %d, c %d\n", ans, a, b, v, c);
        base *= 2;
    }
    return ans;

}
