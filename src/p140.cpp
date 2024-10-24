class Solution {
public:
    vector<int> pos;
    string s;
    vector<string> wordDict;
    vector<string> ans;

    void  dfs(int cur) {
            if (cur >= s.size()) {
                //for (auto c: pos) cout << c << ' ' ; cout << endl;
                string tmp;
                int cur = 0;
                for (int i=0; i<pos.size(); ++i) {
                    tmp += s.substr(cur, pos[i] - cur);
                    if (i != pos.size()-1) tmp += ' ';
                    cur = pos[i];
                    //cout << cur << ' ' << tmp << endl;
                }
                ans.push_back(tmp);
                return;
            } 

            for (auto& w : wordDict)
                if (s.substr(cur, w.size()) == w) {
                    pos.push_back(cur + w.size());
                    dfs(cur + w.size());
                    pos.pop_back();
                }
        }
    vector<string> wordBreak(string s2, vector<string>& wordDict2) {
        s = s2;
        wordDict = wordDict2;
        dfs(0);
        return ans;
    }
};
