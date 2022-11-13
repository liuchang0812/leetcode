class Solution {
public:
    string customSortString(string order, string s) {
        int weight[26];
        memset(weight, 0, sizeof weight);
        for (int i=0; i<order.size(); ++i) weight[order[i] - 'a'] = i+1;
        sort(s.begin(), s.end(), [&](char a, char b) {
            return weight[a-'a'] < weight[b-'a'];
        });
        return s;
    }
};
