class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int has[26];
        memset(has, 0, sizeof has);
        
        for (auto i:letters) 
            has[i-'a'] = 1;
        
        int bg = target -'a' + 1;
        while (!has[bg % 26]) ++bg;
        return char('a' + (bg%26));
    }
};
