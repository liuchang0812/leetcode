class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> sol2id;
        for (int i=0;i<mat.size();++i) {
            int tmp = 0;
            for (int j=0;j<mat[i].size();++j)
                if (mat[i][j] == 1) tmp++;
            sol2id.push_back(make_pair(tmp, i));
        }
        sort(sol2id.begin(), sol2id.end());
        vector<int> ans;
        for (int i=0;i<k;++i)
            ans.push_back(sol2id[i].second);
        return ans;
    }
};
