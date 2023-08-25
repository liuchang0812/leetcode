/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    long long getSum(int x, int y) {
        if (x < 0 || y < 0) return 0;
        return presum[x][y];

    }
    NumMatrix(vector<vector<int>>& matrix) {
        memset(presum, 0, sizeof presum);
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i=0; i<row; ++i) 
            for (int j=0; j<col; ++j) {

                presum[i][j] = matrix[i][j] + getSum(i-1, j) + getSum(i, j-1) - getSum(i-1, j-1);
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row2, col1-1) - getSum(row1-1, col2) + getSum(row1-1, col1-1);
    }
private:
    long long presum[200][200];

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

