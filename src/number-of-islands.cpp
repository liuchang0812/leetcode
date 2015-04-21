class Solution {
public:
    void dfs(vector<vector<char>> &grid, int x, int y, int row, int col)
    {
        if (x < 0 || x >= row) return;
        if (y < 0 || y >= col) return;
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i)
        {
            dfs(grid, x+dx[i], y+dy[i], row, col);
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ans ++;
                    dfs(grid, i, j, row, col);
                }
            }
        return ans;
    }
};
