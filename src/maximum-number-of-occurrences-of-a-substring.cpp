class Solution {
public:
    map<string, bool> visited;
    map<string, int> cnt;
    bool check(const string& s, int pos, int len, int maxLetters) {
        int b[26];memset(b, 0, sizeof b);

        for (int i=pos; i<pos+len; ++i) b[s[i]-'a'] = 1;
        int tmp = 0;
        for(int i=0;i<26;++i) tmp+=b[i];
        return tmp <= maxLetters;
    }
    
    bool same(const string& s, int i, int j, int l) {
        for (int k = 0; k < l; ++k)
            if (s[i+k] != s[j+k]) return false;
        
        return true;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        
        for (int l=minSize; l<=minSize; ++l) {
            for (int i=0; i+l<=s.size(); ++i) {
                if (check(s, i, l, maxLetters)) {
                    cnt[s.substr(i, l)]++;
                }
            }
        }
        for (auto p:cnt) ans = max(ans, p.second);
        return ans;
    }
};
