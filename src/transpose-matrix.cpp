class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ans;
        int n = A.size();
        int m = A[0].size();

        ans.resize(m);
        for (int i=0; i<m; ++i)
            ans[i].resize(n);

        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                ans[j][i] = A[i][j];

        return ans;
    }
};
