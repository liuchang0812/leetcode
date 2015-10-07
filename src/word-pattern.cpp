

class Solution {
public:
    static void str2words(const string& str, vector<string>& words)
    {
        int pre=0;
        for(size_t i=0; i<str.size(); ++i)
        {
            if (str[i] != ' ' ) continue;
            else
            {
                words.push_back(str.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        words.push_back(str.substr(pre));
    }

    bool wordPattern(string pattern, string str) {
        vector<string> words;
        str2words(str, words);
        if (words.size() != pattern.size()) return false;
        vector<string> char2str(256, "papapa");
        map<string, int> used;
        
        for (size_t i=0; i<pattern.size(); ++i)
        {
            //cout << i << ' ' << words[i] << ' ' << char2str[pattern[i]]<< endl;
            if (char2str[pattern[i]] == "papapa")
            {
                if (used[words[i]] == 0)
                {
                    char2str[pattern[i]] = words[i];
                    used[words[i]] ++;
                }
                else return false;
                
            }
            else
            {
                if (char2str[pattern[i]] == words[i]) continue;
                else return false;
            }
        }
        return true;
    }
};

