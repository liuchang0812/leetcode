class Solution {
public:
    set<string> res;
    string path;
    int maxv;

    void dfs(const string& s, int pos, int cur) {
        // cout << "dfs " << pos << ' ' << cur << ' ' << path << endl;
        if (pos == s.size()) {
            if (cur == 0)
                res.insert(path);
            return;
        }

        if (cur > maxv)
            return;

        if (s[pos] != '(' && s[pos] != ')') {
            path = path + s[pos];
            dfs(s, pos + 1, cur);
        }

        if (s[pos] == '(') {
            auto orig = path;
            path = path + s[pos];
            dfs(s, pos + 1, cur + 1);
            path = orig;

            dfs(s, pos + 1, cur);
        }

        if (s[pos] == ')') {

            if (cur > 0) {
                auto orig = path;
                path = path + s[pos];
                dfs(s, pos + 1, cur - 1);
                path = orig;
            }

            dfs(s, pos + 1, cur);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        maxv = 0;
        for (auto c : s)
            maxv += c == ')';

        path = "";
        dfs(s, 0, 0);
        unsigned long sz = 0;
        for (auto& s : res) {
            sz = max(sz, s.size());
        }

        vector<string> ans;
        for (auto& s : res) {
            if (s.size() == sz)
                ans.push_back(s);
        }
        return ans;
    }
};
