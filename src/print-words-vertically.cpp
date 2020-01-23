class Solution {
public:
    vector<string> printVertically(string s) {
        int p = 0, l = 0;
        int i = 0;
        vector<string> words;
        int _max_len = 0;
        for(; i<s.size(); ++i) {
            if (s[i] == ' ') {
                words.push_back(s.substr(p, l));
                _max_len = max(_max_len, l);
                p = i+1;
                l = 0;
            }
             else {
            ++l;
             }
        }
        if(l) _max_len = max(_max_len, l), words.push_back(s.substr(p, l));
        //for(auto i:words) cout << i << endl;
        
        vector<string> ans;
        for (int i=0; i<_max_len; ++i) {
            string tmp; 
            for (int j=0;j<words.size(); ++j) 
                if (i<words[j].size()) tmp += words[j][i]; else tmp+=' ';
            
            int x = 0, p = tmp.size()-1;
            while(tmp[p] == ' ') {
                ++x;--p;
            }
            ans.push_back(tmp.substr(0, tmp.size()-x));
        }
        return ans;
    }
};
