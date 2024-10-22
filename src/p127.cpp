class Solution {
public:

    vector<vector<string>> ans;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> wordMap;
        for (auto w : wordList) wordMap[w] = true;

        queue<string> qs;
        queue<int> qi;

        int min_depth = INT_MAX;

        qs.push(beginWord);
        qi.push(1);

        map<string, int> has;
        map<string, string> pre;
        has[beginWord] = 1;



        while (!qs.empty()) {
            auto cur = qs.front(); qs.pop();
            auto cur_depth = qi.front(); qi.pop();
            // cout << cur_depth << " " << cur << endl;

             if (cur == endWord) {
                return cur_depth;
            }

            {
                auto is_next = [&](const string& s) {
                    // cout << "has " << s << ' ' << (has.count(s) > 0) << endl;
                    // if (has.count(s) > 0 ) cout << "has[s]: " << has[s] << endl;
                    if (has[s]) return false;
                    return true;
                };
                auto maybe = [&](const string& s) {
                    vector<string> ss;
                    string t;
                    for (int i=0; i<s.size(); ++i) 
                        for (int j=0; j<26; ++j) {
                            if (s[i] == 'a' + j) continue;
                            t = s;
                            t[i] = 'a' + j;
                            if (wordMap[t])
                                ss.push_back(t);
                        }
                    return ss;
                };
                auto maybe_words = maybe(cur);

                for (auto word: maybe_words) {
                    if (is_next(word)) {
                            // cout << "update pre: " << word << " --> " << cur << endl;
                            qs.push(word);
                            qi.push(cur_depth + 1);
                            has[word] = 1;
                    }
                }
            }
        }
        return 0;
    }
};
