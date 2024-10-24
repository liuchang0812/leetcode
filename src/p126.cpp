class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, bool> wordMap;
    vector<string> path;
    void dfs(map<string, vector<string>>& from, const string& beginWord,
             const string& endWord) {
        if (endWord == beginWord) {
            auto tmp = path;
            tmp.push_back(beginWord);
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        } else {
            for (auto s : from[endWord]) {
                path.push_back(endWord);
                dfs(from, beginWord, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        for (auto word : wordList)
            wordMap[word] = true;
        if (!wordMap[endWord])
            return ans;
        wordMap[beginWord] = false;

        queue<string> qs;
        map<string, int> depth;
        map<string, vector<string>> from;

        qs.push(beginWord);
        int step = 0;
        bool found_ans = false;
        while (!found_ans && !qs.empty()) {
            ++step;
            vector<string> ss_this_level;
            // cout <<"qs size: " << qs.size() << endl;
            while (!qs.empty()) {
                ss_this_level.push_back(qs.front());
                qs.pop();
            }

            // cout << step << ' ';
            // for (auto s : ss_this_level) cout << s << ' ' ;
            // cout << endl;
            set<string> next_leve;
            for (auto s : ss_this_level) {

                string origin = s;

                for (int i = 0; i < s.size(); ++i) {
                    for (int j = 0; j < 26; ++j) {
                        if (s[i] == 'a' + j)
                            continue;
                        s[i] = 'a' + j;

                        if (wordMap[s] == true &&
                            (depth.count(s) == 0 || depth[s] == step)) {
                            depth[s] = step;
                            from[s].push_back(origin);
                            next_leve.insert(s);
                            // wordMap[s] = false;
                        }
                        if (s == endWord)
                            found_ans = true;
                        s = origin;
                    }
                }
            }

            for (auto s : next_leve)
                qs.push(s);
        }
        // for (auto p : from) {
        //     cout << p.first << ' ' ;
        //     for (auto s: p.second)
        //         cout << s << ' ';
        //     cout << endl;
        // }

        dfs(from, beginWord, endWord);
        return ans;
    }
};
