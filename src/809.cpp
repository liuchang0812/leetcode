class Solution {
public:
    
    vector<pair<char, int>> genCharCount(string s) {
        vector<pair<char, int>> char_count;

        char cur_char = s[0];
        int cur_count = 1;
        for (int i=1; i<s.size(); ++i) {
            if (s[i] == cur_char) ++cur_count;
            else {
                cout << "push " << cur_char << cur_count << endl;
                char_count.emplace_back(make_pair(cur_char, cur_count));
                cur_char = s[i];
                cur_count = 1;
            }
        }

        if (cur_count) {
            char_count.emplace_back(make_pair(cur_char, cur_count));
        }

        return char_count;
    }

    bool f(const vector<pair<char, int>>& count1, const vector<pair<char, int>>& count2) {
        if (count1.size() !=  count2.size()) return false;

        for (int i=0; i<count2.size(); ++i) {
            auto p1 = count1[i];
            auto p2 = count2[i];

            if (p1.first != p2.first) return false;
            cout << p1.second << ' ' <<  p2.second  << endl;

            if (p1.second < 3 && p1.second != p2.second) return false;
            if (p1.second < p2.second) return false;

        }
        return true;
    }

    int expressiveWords(string s, vector<string>& words) {
        auto s_char_count = genCharCount(s);

        int ans = 0;

        for (auto& word : words) {
            auto word_char_count = genCharCount(word);

            if (f(s_char_count, word_char_count)) {++ans; cout << word << endl; }
        }
        return ans;
    }
};
