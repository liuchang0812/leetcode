/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        auto words = wordlist;
        vector<string> words2;
        for (int i=0;i <10; ++i) {
            int x = rand() % words.size();
            int y = master.guess(words[x]);
            if (y==6) return;
            for (int j=0; j<words.size(); ++j)
            {
                int tmp = 0;
                for (int k=0; k<6; ++k) if (words[x][k] == words[j][k]) tmp++;
                
                if (tmp == y)
                    words2.push_back(words[j]);
            }
            words = words2;
            words2.clear();
        }
    }
};
