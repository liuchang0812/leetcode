class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int f[5005][505];
        memset(f, 0, sizeof f);
        for (int i=0; i<505; ++i)
            f[0][i] = 1;
        sort(coins.begin(), coins.end());
        for (int i=1; i<=amount; ++i) {
          for (int j=0; j<coins.size(); ++j) {
            for (int k=0; k<=i/coins[j]; ++k) {
               f[i][j+1] += f[i-coins[j]*k][j];
            }
            //cout << "i, j: " << f[i][j+1] << endl;
          }
        }
        return f[amount][coins.size()];
    }
};
