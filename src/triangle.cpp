class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0)return 0;
        int n = triangle[triangle.size()-1].size();
        vector<int> f(n+1,INT_MAX);
        f[1] = triangle[0][0];
        for(int i=1; i<triangle.size(); ++i)
        {
            int len = triangle[i].size();
            for(int j = len; j > 0; --j)
            {
                f[j] = min(f[j], f[j-1]) + triangle[i][j-1];
            }
        }
        int ans = INT_MAX;
        for(int i=1; i<=n; i++)
            ans = min(ans, f[i]);
        return ans;
    }
};
