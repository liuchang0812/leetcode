class Solution {
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u' ||
               c == 'A' || c == 'O' || c == 'I' || c == 'E' || c == 'U';
    }
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        while (i < j)
        {
            while (i < s.size() && !isVowel(s[i])) ++i;
            while (j >= 0 && !isVowel(s[j])) --j;
            
            //cout << i << ' ' << j << endl;
            if (i < s.size() && j >= 0 && i < j) 
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
