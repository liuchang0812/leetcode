class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // arr.size() < 100, arr[i] < 200

        bool f[201][20001];  // f[i][j] =
        memset(f, 0, sizeof f);
        f[0][0] = true;

        int sums[201];
        sums[0] = 0;
        for (int i=1; i<=nums.size(); ++i)
                sums[i] = sums[i-1] + nums[i-1];

        for (int i=1; i<=nums.size(); ++i)
        {
                for (int j=0; j<=sums[i]; ++j) {
                        f[i][j] = f[i-1][j+nums[i-1]] || f[i-1][abs(j-nums[i-1])];
                    //cout << i << ' ' << j << ' ' << f[i][j] << endl;
                }
        }
        return f[nums.size()][0];
    }
};
