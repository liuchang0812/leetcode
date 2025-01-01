class Solution {
public:
    using pp = pair<int, int>;

    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pp> cost;

        for (auto i:horizontalCut)
            cost.push_back({i, 1});
        for (auto i:verticalCut)
            cost.push_back({i, 0});

        sort(cost.begin(), cost.end(), [&](pp& a, pp& b) { return a.first > b.first; });

        int r_cut = 1;
        int c_cut = 1;
        long long res = 0;
        for (int i=0;i<cost.size(); ++i) {
            bool row = cost[i].second;
            long long cc = cost[i].first;
            //cout << i << ' ' << row << ' ' << cc << endl;
            if (row) {
                ++r_cut;
                res += cc * c_cut;
            } else {
                ++c_cut;
                res += cc * r_cut;
            }

            //cout << "res " << res << ' ' << c_cut << ' ' << r_cut << endl;
        }
        return res;
    }
};