
class Solution {
private:
    bool mPalin[1005][1005];
    bool isPali(const string &s, int i, int j) {
        int bg = i, ed = j;
        while (bg < ed && s[bg] == s[ed]) {
            bg ++;
            ed --;
        }
        return bg >= ed;
    }
    
    void init(const string &s)
    {
        for (int i = 0; i<s.size(); i++)
            for (int j=i; j<s.size(); j++)
            {
                if (this->isPali(s, i, j))
                	this->mPalin[i][j] = 1;
                else this->mPalin[i][j] = 0;
            }
    }
    vector<vector<string> > anss;
    vector<string> ans;
    void dfs(string &s, int cur, vector<string> v) {

        if (cur >= s.size()) {
            anss.push_back(v);
            return;
        }
        for (int i = cur; i < s.size(); i ++)
        {
            if (mPalin[cur][i]) {
                
                v.push_back(s.substr(cur, i-cur+1));
                dfs(s, i+1, v);
                v.pop_back();
            }
        }
    }
    
public:
    vector<vector<string> > partition(string s) {
        memset(mPalin, 0, sizeof mPalin);
        init(s);
        dfs(s, 0, ans);
        return anss;
    }
};
