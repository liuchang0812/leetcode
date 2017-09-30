class Solution {
public:
    bool _valid(const string& s, int bg, int ed) {
        int i = bg;
        int j = ed;
        while (i < j && s[i] == s[j]) {
            i ++;
            j --;
        }
        return i>=j;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while (i < j && s[i] == s[j]) {
            i ++;
            j--;
        }
        if (i>=j) return true;
        return _valid(s, i+1, j) || _valid(s, i, j-1);
    }
};
