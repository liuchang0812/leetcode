class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(cache, 0, sizeof cache);
        cache[1][1] = 1;
        return f(m, n);
    }
    
    int f(int m, int n) {
        if (n<=0) return 0;
        if (m<=0) return 0;
        if (cache[m][n] == 0){  return (cache[m][n] = f(m-1,n) + f(m, n-1)), cache[m][n];}
        else return cache[m][n];
    }
    int cache[102][102];
};
