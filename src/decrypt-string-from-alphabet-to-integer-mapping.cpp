class Solution {
public:
    char mpp(const string& s) {
        int x = (s[0] - '0') * 10 + s[1] - '0';
        return char('j' + x - 10);
    }
    string freqAlphabets(string s) {
        vector<int> pos;
        for (int i=0;i<s.size();++i)
            if (s[i] == '#')
                pos.push_back(i);
        
        string ans;
        int i=0;
        int pi = 0;
        while(i<s.size()) {
            if (pi != pos.size() && i+2 == pos[pi]) {
                string tmp = s.substr(i, 2);
                i += 3;
                ans += mpp(tmp);
                ++pi;
            } else {
                ans += char('a' + s[i] - '0' - 1);
                i += 1;
            }
        }
        return ans;
    }
};
