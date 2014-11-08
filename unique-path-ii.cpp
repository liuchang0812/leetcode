class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        cache[1][1] = 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i=1; i<= m; i++)
            for (int j=1;j <=n; j++)
            {
                if (obstacleGrid[i-1][j-1] == 1) cache[i][j] = 0;
                else cache[i][j] = -1;
            }
        if (cache[1][1] == 0) return 0;
        else cache[1][1] = 1;
        return f(m, n);
    }
    
    int f(int m, int n) {
        if (n<=0) return 0;
        if (m<=0) return 0;
        if (cache[m][n] == -1){  return (cache[m][n] = f(m-1,n) + f(m, n-1)), cache[m][n];}
        else return cache[m][n];
    }
    int cache[102][102];
};
