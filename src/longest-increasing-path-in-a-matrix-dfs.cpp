#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(const vector<vector<int> >& matrix, int x, int y)
    {
        static int dx[] = {0, 0, -1, 1};
        static int dy[] = {-1, 1, 0, 0};

        int ret = 0;

        for (int i=0; i<4; ++i)
        {
            int px = x + dx[i];
            int py = y + dy[i];

            if (px < 0 || px >= matrix.size() || py < 0 || py >= matrix[0].size()) continue;
            if (matrix[x][y] > matrix[px][py])
                ret = max(ret, dfs(matrix, px, py));
        }
        cout << "dfs " << x << ' ' << y << ' ' << ret + 1 <<  endl;

        return ret + 1;
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int ans = 0;

        for (int i=0; i< matrix.size(); ++i)
            for (int j=0; j<matrix.size(); ++j)
            {
                ans = max(ans, dfs(matrix, i, j));
            }
        return ans;
    }
};


int main()
{
    vector<vector<int> > inp;
    vector<int> tmp;
    tmp.push_back(9);
    tmp.push_back(9);
    tmp.push_back(4);
    inp.push_back(tmp);
    tmp.clear();
    tmp.push_back(6);
    tmp.push_back(6);
    tmp.push_back(8);
    inp.push_back(tmp);
    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(1);
    tmp.push_back(1);
    inp.push_back(tmp);

    cout << Solution().longestIncreasingPath(inp)<<endl;
    return 0;
}
