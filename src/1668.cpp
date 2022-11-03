class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        int cur = 0;

        int i=0;
        int j=0;
        while (i<sequence.size()) {
            if (sequence[i] == word[j]) {
                ++j;
                ++i;
                if (j == word.size()) {
                    ++cur;
                    if (cur > ans) ans = cur;
                    j = 0;
                }
            } else {
                if (cur > 0) {
                    i = i - j + 1 - word.size();
                } else {
                    i = i - j + 1;
                }
                j = 0;
                cur = 0;
            }
        }


        return ans;
    }
};
