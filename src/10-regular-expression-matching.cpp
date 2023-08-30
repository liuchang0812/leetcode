class Solution {
public:
    map<int, map<int, int>> cache; // 2 true 1 false;
    bool isMatch(string s, string p, int i=0, int j=0) {
        if (cache[i][j] != 0) return cache[i][j] == 2; 
        cout << i << ' ' << j << endl;
        bool res = [&]{
        if (i > s.size() || j > p.size()) return false;
        if (i >= s.size() && j >= p.size()) return true;

        if (p[j] == '.') {
            if (j+1 < p.size() && p[j+1] == '*') {
                for (int k=s.size(); k>=i; --k)
                    if (isMatch(s, p, k, j+2)) return true;
                return false;
            }
            else 
                return isMatch(s, p, i+1, j+1);
        } else if (p[j] != '*') {
            if (j+1 < p.size() && p[j+1] == '*') {
                bool zero = isMatch(s, p, i, j+2);
                if( zero) return true;
                for (int k=i; k<s.size();++k)
                    if (s[k] != p[j]) break;
                    else {
                        if (isMatch(s, p, k+1, j+2))
                        return true;
                    }
                return false;
            } else {
                return s[i] == p[j] && isMatch(s, p, i+1, j+1);
            }

        } else {
            return isMatch(s, p, i, j+1);
        }
        }();
        if (res) cache[i][j] = 2;
        else cache[i][j] = 1;
        return res;
    }
};
