
#define max_ 501
class Solution {
public:
	int f[max_][max_];
    bool solve(int bg, int ed)
    {
        if (bg > ed) return false;
        if (f[bg][ed] == 1) return true;
        if (f[bg][ed] == 0) return false;
        for(size_t k = bg; k < ed; ++k)
        {
            if ( solve(bg, k) && solve(k+1, ed) )
            {
            	f[bg][ed] = 1;
                return true;
            }
        }
        f[bg][ed] = 0;
        return false;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        int s_len = s.size();
        for (size_t i=0; i<max_; ++i)
            for (size_t j=0; j<max_; ++j)
                f[i][j] = INT_MAX;
                
        for (unordered_set<string>::iterator p = dict.begin(); p!=dict.end(); p++)
        {
            string tmp = *p;
            int cur = 0, index = 0;
            while ((index =s.find(tmp, index))!=string::npos)
            {
                f[index ][index + tmp.size() - 1] = 1;
                index ++;
            }
        }
        return solve(0, s_len-1);
    }
};
