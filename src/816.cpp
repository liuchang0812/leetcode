class Solution {
  public:
      string gen(const string& s, int bg, int ed, int dot) {
        if (dot >= ed) return s.substr(bg, ed - bg + 1);
        else return s.substr(bg, dot - bg + 1) + "." + s.substr(dot+1, ed - dot);
      }

      bool isValid(const string& s, int bg, int ed, int dot) {
        if (bg == ed) return true;
        if (dot >= ed) {
          if (s[bg] == '0') return false; 
          return true;
        }
        if (dot - bg > 0) {
          if (s[bg] == '0') return false;
        }

        if (dot < ed) {
          if (s[ed] == '0') return false;
        }
        return true;
      }

      vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.size()-2);
        for (int cnt = 1; cnt < s.size(); ++cnt) 
          for (int i=0; i<cnt; ++i)
            for (int j=cnt; j<s.size(); ++j) {
              if (isValid(s, 0, cnt-1, i) && 
                isValid(s, cnt, s.size()-1, j)) {
                  ans.push_back("(" + gen(s, 0, cnt-1, i) + ", " + gen(s, cnt, s.size()-1, j) + ")");
                 cout << cnt << ' ' << i << ' ' << j << endl;
              }
            }
          return ans;
      }
  };
