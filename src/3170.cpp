class Solution {
public:
    string clearStars(string s) {
        vector<int> pos[26];
        set<int> del;

        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '*') {
                for (int j=0; j<26;++j) {
                    if (pos[j].size() == 0) continue;
                    int idx = pos[j].back(); pos[j].pop_back();
                    del.insert(idx);
                    break;
                }
            } else {
                int idx = s[i] - 'a';
                pos[idx].push_back(i);
            }
        }

        string res;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '*' || del.find(i) != del.end()) continue;
            res += s[i];
        }
        return res;
    }
};