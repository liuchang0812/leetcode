class Solution {
public:
    bool ok(const vector<vector<int>>& postion, const string& word) {
        int cur = -1;
        for (auto c : word) {
            auto p = upper_bound(postion[c-'a'].begin(), postion[c-'a'].end(), cur);
            if (p == postion[c-'a'].end()) return false;
            else {
                cur = *p;
            }
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> postion;
        postion.resize(26);
        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
            postion[c-'a'].push_back(i);
        }
        int ans = 0;
        for (auto word : words) 
            if (ok(postion, word)) ++ans;
        return ans;

    }
};
