
class Solution {
public:
    vector<vector<string>> ans;
    int queue[9];
    bool valid(int cur, int nx, int ny) {
        for (int i = 0; i<cur; ++i) {
            if (queue[i] == ny) return false;

            if (queue[i] - i == ny - nx) return false;

            if (queue[i] + i == ny + nx) return false;

        }

        return true;  
    }

    void nqueue(int n, int cur) {
        if (cur >= n) {
            // find a ans
            vector<string> sol;
            for (int i=0; i<n; ++i) {
                // cout << i << ' ' << queue[i] << endl;
                string re;
                for (int j=0; j<n; ++j) {
                    if (queue[i] == j) re += 'Q';
                    else re += '.';
                }
                sol.push_back(re);
            }
            ans.push_back(sol);
            return;
        } else {
            for (int i=0; i<n; ++i) {
                int nx = cur, ny = i;

                if (valid(cur, nx, ny)) {
                    queue[cur] = ny;
                    nqueue(n, cur+1);
                }
            }
        }
    }
    int totalNQueens(int n) {
        nqueue(n, 0);
        return ans.size();
    }
};
