class Solution {
public:
    bool isMagicSquares(vector<vector<int>>& grid, int x, int y) {
        int x2 = x + 2; 
        int y2 = y + 2;
        if (x2 >= grid.size() || y2 >= grid[0].size()) return false;
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                if (grid[x+i][y+j] > 9 || grid[x+i][y+j] < 1) return false;
        int _sum = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        
        for (int i=0; i<3; ++i) {
            if (grid[x][y+i] + grid[x+1][y+i] + grid[x+2][y+i] != _sum) return false;
        }
        
        for (int i=0; i<3; ++i) {
            if (grid[x+i][y] + grid[x+i][y+1] + grid[x+i][y+2] != _sum) return false;
        }
        
        if (grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] != _sum) return false;
        if (grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y] != _sum) return false;
        cout << x << ' ' << y << endl;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j)
                ans += isMagicSquares(grid, i, j);
        return ans;
    }
};
