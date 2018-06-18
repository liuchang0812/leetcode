class Solution {
public:
    int countSubstrings(string s) {
        int f[1000][1000];
        
        for (int i=0;i<s.size();++i)
            for (int j=s.size()-1; j>=0; --j)
            {
                if (j > i) f[j][i] = true;
                if (j == i) f[j][i] = true;
                if (j < i) {
                    if (s[i] == s[j] && f[j+1][i-1]) f[j][i] = true;
                    else f[j][i] = false;
                }
            }
                
        int ans = 0;
        for (int i=0; i<s.size(); ++i)
            for (int j=0; j<=i; ++j)
                if (f[j][i]) ++ans;
        return ans;
    }
};
