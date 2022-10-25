#include <iostream>
#include <map>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
 public:
  map<int, map<int, bool>> visited;
  queue<tuple<int, int, int>> Q;

  void dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
    if (visited[x][y]) return;
    if (grid[x][y] == 0) return;

    visited[x][y] = true;
    Q.push(tuple<int, int, int>{x, y, 0});

    dfs(grid, x - 1, y);
    dfs(grid, x + 1, y);
    dfs(grid, x, y - 1);
    dfs(grid, x, y + 1);
  }

  int shortestBridge(vector<vector<int>>& grid) {
    // find first 1
    int first_x, first_y;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1) {
          first_x = i;
          first_y = j;
        }
    dfs(grid, first_x, first_y);

    while (Q.size()) {
      auto item = Q.front();
      Q.pop();
      int x, y, d;
      tie(x, y, d) = item;
      // cout << x << ' ' << y << ' ' << d << endl;
      static int dx[] = {-1, 1, 0, 0};
      static int dy[] = {0, 0, -1, 1};
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nd = d + 1;

        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() ||
            visited[nx][ny])
          continue;
        if (grid[nx][ny] == 1) {
          // cout << "ans: " << nx << ' ' << ny << ' ' << d << endl;
          return d;
        }
        visited[nx][ny] = 1;
        Q.push(tuple<int, int, int>{nx, ny, nd});
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> inp = {{1, 1, 1, 1, 1},
                             {1, 0, 0, 0, 1},
                             {1, 0, 1, 0, 1},
                             {1, 0, 0, 0, 1},
                             {1, 1, 1, 1, 1}};
  sol.shortestBridge(inp);
  return 0;
}
