class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        queue<int> lens;
        map<int, map<int , bool>> visited;
        
        if (grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1) return -1;
        
        Q.push(make_pair(0,0));
        lens.push(1);
        visited[0][0] = true;
        while (!Q.empty()) {
            auto pos = Q.front();Q.pop();
            auto ans = lens.front();lens.pop();
            if (pos.first == grid.size() -1 && pos.second == grid[0].size()-1)
                return ans;
            
            static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (int i = 0; i<8; ++i)
            {
                int x = pos.first + dx[i];
                int y = pos.second + dy[i];
                if (x >= 0 && y >= 0 &&
                    x < grid.size() &&
                    y < grid[0].size() && grid[x][y] == 0 &&
                   visited[x][y] == false)
                {
                    Q.push(make_pair(x, y));
                    lens.push(ans+1);
                    visited[x][y] = true;
                }
            }
        }
        return -1;
    }
};
