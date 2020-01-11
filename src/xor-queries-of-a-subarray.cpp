class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // xor[i,j] = xor[0, j] ^ xor[0,i-1]
        int f[30005];
        memset(f, 0, sizeof f);
        f[0] = arr[0];
        for (int i=1; i<arr.size();++i)
            f[i] = arr[i] ^ f[i-1];
        vector<int> ans;
        for (int i=0; i<queries.size(); ++i) {
            int a, b;
            a = queries[i][0];
            b = queries[i][1];
            if (a == 0) ans.push_back(f[b]);
            else 
                ans.push_back(f[b] ^ f[a-1]);
        }
        return ans;
    }
};
