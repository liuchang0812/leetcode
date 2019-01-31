class Solution {
public:
    void findAnyIsland(vector<vector<int>>& A, int& x, int& y) {
        for (int i=0;i<A.size(); ++i)
            for (int j=0; j<A[0].size(); ++j)
                if (A[i][j] == 1) {
                    x = i;
                    y = j;
                    return;
                }
    }

    void fill(vector<vector<int>>& A, int x, int y) {
        if (x < 0 || y < 0 || x >= A.size() || y >= A[0].size())
            return;

        if (A[x][y] == 0 || A[x][y] == 2) return;
        A[x][y] = 2;
        //cout << "fill " << x << ' ' << y << " to 2" << endl;
        fill(A, x-1, y);
        fill(A, x+1, y);
        fill(A, x, y-1);
        fill(A, x, y+1);
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int x, y;
        findAnyIsland(A, x, y);
        //cout << "find island " << x << ' ' << y << endl;

        fill(A, x, y);

        int ans = INT_MAX;
        for (int i=0; i<A.size(); ++i)
            for (int j=0; j<A[0].size(); ++j)
                for (int i2=0; i2<A.size(); ++i2)
                    for (int j2=0; j2<A[0].size(); ++j2) {
                        if (A[i][j] != 0 && A[i2][j2] != 0 && A[i][j] != A[i2][j2]) {
                            //cout << "update ans" << endl;
                            ans = min(ans, abs(i-i2) + abs(j-j2) - 1);
                        }
                    }
        return ans;
    }
};
