class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        
        int col = matrix[0].size();
        
        int len = min(row, col);
        
        bool f[row][col][2];
        
        int ans = 0;
        
        for (int i=0; i<row; ++i)
            for (int j=0; j<col; ++j)
            if (matrix[i][j]=='1')
            {
                f[i][j][0] = true;
                ans = 1;
                //cout << i << ' ' << j << ' ' << 0 << ' ' << f[i][j][0] << endl;
            }
            else
                f[i][j][0] = false;
 
        for (int k=2; k<=len; ++k)
        {
            for (int i=k-1; i<row; ++i)
                for (int j=k-1; j<col; ++j)
                {
                    if (f[i-1][j-1][k%2] && f[i-1][j][k%2] && f[i][j-1][k%2] && matrix[i][j] == '1')
                    {
                        f[i][j][(k+1)%2] = true;
                        ans = max(ans, k*k);
                    }
                    else
                        f[i][j][(k+1)%2] = false;
                    //cout << i << ' ' << j << ' ' << k << ' ' << k%2 << ' ' << f[i][j][(k+1)%2] << endl;
                }
        }
        
        return ans;
    }
};
