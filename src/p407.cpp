typedef pair<int, int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
            return 0;
        } 

        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        map<pii, bool> visit;

        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (i==0 || j == 0 || i == n-1 || j == m-1) {
                    pq.push({heightMap[i][j], i*m+j}); // value, pos
                    visit[{i, j}] = true;
                }

        int res = 0;
        while (!pq.empty()) {
            pii cur = pq.top(); pq.pop();

            int cx = cur.second / m;
            int cy = cur.second % m;
            static int dx[4] = {-1, 1, 0, 0};
            static int dy[4] = {0, 0, -1, 1};

            for (int k=0; k<4; ++k) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[{nx, ny}]) {

                    if (heightMap[nx][ny] < cur.first) {
                        res += (cur.first - heightMap[nx][ny]);
                    }

                    visit[{nx, ny}] = true;
                    pq.push({max(heightMap[nx][ny], cur.first), nx * m + ny});
                }
            }
        }
        return res;

    }
};
