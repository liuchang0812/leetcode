class Solution {
public:
    int X,Y;
    vector<vector<int>> _sum;
    vector<vector<int>> ans;
    int __sum(int x, int y) {
        if (x < 0 || y < 0) return 0;
        if (x > X) x = X;
        if (y > Y) y = Y;
        //cout << "__sum: " << x << ' ' << y << ' ' << _sum[x][y] << endl;

        return _sum[x][y];
    }
    int _getSum(int x, int y, int v = 0) {
        return __sum(x, y-1) + __sum(x-1, y) - __sum(x-1, y-1) + v;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        _sum.resize(mat.size());
        ans.resize(mat.size());
        X = mat.size()-1;
        Y = mat[0].size()-1;
        for (int i=0;i<mat.size(); ++i)
            for (int j=0;j<mat[0].size();++j) {
                _sum[i].push_back(_getSum(i, j, mat[i][j]));
                //cout << i << ' ' << j << ' ' << _sum[i][j] << endl;
            }
        for (int i=0;i<mat.size();++i) 
            for (int j=0;j<mat[0].size();++j) {
                // x+K, y+K
                ans[i].push_back(__sum(i+K, j+K) - __sum(i-K-1, j+K) - __sum(i+K, j-K-1)+__sum(i-K-1, j-K-1));
                //cout << i << ' ' << j << ' ' << ans[i][j] << endl;
            }
        return ans;
    }
};
