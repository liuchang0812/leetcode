/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 *
 * [2328] 网格图中递增路径的数目
 */

// @lc code=start
class Solution {
public:
  int M = 1000000007;
  int row, col;
  int dp[1005][1005];
  int dfs(int i, int j, int row, int col, const vector<vector<int>> &grid) {
    if (dp[i][j] != -1)
      return dp[i][j];
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};

    long long count = 1;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dx[d];
      int nj = j + dy[d];
      if (ni >= 0 && ni < row && nj >= 0 && nj < col &&
          grid[i][j] > grid[ni][nj]) {
        // cout << len << ' ' << ni << ' ' << nj << ' '  << dp[ni][nj][idx] <<
        // endl;
        count += 0ll + dfs(ni, nj, row, col, grid);
        count %= M;
      }
    }
    dp[i][j] = count;
    return count;
  }

  int countPaths(vector<vector<int>> &grid) {
    row = grid.size();
    col = grid[0].size();

    // memset(dp, 0, sizeof dp);
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        dp[i][j] = -1;

    long long ans = 0;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (dp[i][j] == -1)
          dfs(i, j, row, col, grid), ans %= M;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) {
        ans += dp[i][j];
        ans %= M;
      }
    return ans;
  }
};
// @lc code=end
