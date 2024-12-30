class Solution {
public:
    string rankTeams(vector<string>& votes) {
        auto len = votes[0].size();

        int f[26][1000];
        memset(f, 0, sizeof f);

        for (auto& v : votes)
            for (int i=0; i<v.size(); ++i) {
                auto c = v[i];
                ++f[c-'A'][i];
                //cout << c-'A' << ' ' << i << endl;
            }
        
        string res = votes[0];

        sort(res.begin(), res.end(), [&](char a, char b) {
            for (int i=0; i<1000; ++i) {
                if (f[a-'A'][i] ==  f[b-'A'][i]) continue;
                if (f[a-'A'][i] < f[b-'A'][i]) return false;
                else return true;
            }
            return a < b;
        });
        return res;
    }
};