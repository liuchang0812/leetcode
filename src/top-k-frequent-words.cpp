class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> cnt;
        for (auto &i: words)
            ++ cnt[i];
        typedef pair<int, string> cntPair;
        vector<cntPair> tmp;
        for (auto i: cnt) {
            tmp.push_back(make_pair(i.second, i.first));
        }

        sort(tmp.begin(), tmp.end(), [](cntPair x, cntPair y) {
            return x.first > y.first ||
                    x.first == y.first && x.second <= y.second;
        });
        vector<string> ans;
        for (int i=0; i<k; ++i)
            ans.push_back(tmp[i].second);
        return ans;
    }
};
