class Solution {
public:
    vector<int> mpp;
    vector<bool> used;
    vector<string> _words;
    string _result;
    
    bool dfs(int step, vector<int>& mpp, vector<bool>& used, int jw, int has, string cur, char rel) {
    //{ cout << step <<' ' << jw <<  ' ' << has << ' ' << cur << ' ' << rel << endl; 
     //for (int i=0;i <mpp.size(); ++i) if (mpp[i]!=-1) cout <<"  " << char(i+'A') << " --> " << mpp[i] << endl;
    //}
        if (cur.empty()) {
            if (mpp[rel-'A'] == -1 && used[(has+jw)%10]==false ) {
                mpp[rel-'A'] = (has+jw) % 10;
                
                used[(jw+has)%10] = true;
                jw = (jw+has)/10;
                if (step+1 == _result.size())
                {
                    //cout << "find one " << jw << endl;
                    //for (int i=0;i <mpp.size(); ++i) if (mpp[i]!=-1) cout <<"  " << char(i+'A') << " --> " << mpp[i] << endl;
                    return jw == 0;
                }   
                else {
                    bool tmp =  dfs(step+1, mpp, used, jw, 0, _words[step+1], _result[step+1]);
                    int _t = mpp[rel-'A'];
                    mpp[rel-'A'] = -1;
                    used[_t] = false;
                    return tmp;
                }
            } else if (mpp[rel-'A'] == (has+jw)%10) {
                
                jw = (jw+has) / 10;
                if (step+1 == _result.size())
                {
                    //cout << "find one " << jw << endl;
                    //for (int i=0;i <mpp.size(); ++i) if (mpp[i]!=-1) cout <<"  " << char(i+'A') << " --> " << mpp[i] << endl;
                     return jw == 0;
                }

                else {
                    //cout <<"ooops" << endl;
                    bool tmp =  dfs(step+1, mpp, used, jw, 0, _words[step+1], _result[step+1]);

                    return tmp;
                
                }
                    
            } else 
                return false;
        } else {
            char toTry = cur[0];
            if (mpp[toTry-'A']!=-1) {
                return dfs(step, mpp, used, jw, has+mpp[toTry-'A'], cur.substr(1), rel);
            }
            
            else {
                for (int i=0;i<10;++i) {
                    if (used[i]==false) {
                        mpp[toTry-'A'] = i;
                        used[i] = true;
                        //cout << " try " << i << " for " << toTry << endl;
                        if (dfs(step, mpp, used, jw, has+mpp[toTry-'A'], cur.substr(1), rel) == true)
                            return true;
                        mpp[toTry-'A'] = -1;
                        used[i] = false;
                    }
                }
                return false;
            }
        }
        return false;
    }
    
    
    bool isSolvable(vector<string>& words, string result) {
        reverse(result.begin(), result.end());
        _result = result;
        for (int i=0;i < words.size(); ++i)
            reverse(words[i].begin(), words[i].end());
        
        for (int i=0;i < result.size(); ++i)
        {
            string tmp;
            for (int j=0;j<words.size();++j)
                if (words[j].size() > i) tmp += words[j][i];
            _words.push_back(tmp);
        }
        
        for(int i=0; i<26; ++i) mpp.push_back(-1);
        for(int i=0; i<10; ++i) used.push_back(false);
        //return true;
        return dfs(0, mpp, used, 0, 0, _words[0], _result[0]);
    }
};
