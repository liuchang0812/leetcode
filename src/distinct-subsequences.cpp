class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        
        int f[len1+1][len2+1];
        memset(f, 0, sizeof f);
        
        for (int i=0; i<=len1; ++i)
            for (int j=i+1; j<=len2; ++j)
                f[i][j] = -1;
        for (int i=0; i<=len1; ++i)
            f[i][0] = 1;
        
        for (int j=1; j<= len2; ++j)
            for (int i=j; i<=len1; ++i)
            {
                int p1, p2;
                p1 = i-1; p2 = j-1;
                
                if (s[p1] == t[p2])
                {
                    int cnt = f[i-1][j-1];
                    int cnt2 = f[i-1][j] == -1 ? -1 : (f[i-1][j] == 0? 1 : f[i-1][j]);
                    
                    if (cnt == -1 && cnt2 == -1)
                        f[i][j] = -1;
                    else
                    {
                        int ans = 0;
                        if (cnt != -1) ans += cnt;
                        if (cnt2 != -1) ans += cnt2;
                        f[i][j] = ans;
                    }
                }
                else
                {
                    int cnt = f[i-1][j];
                    if (cnt == -1)
                        f[i][j] = -1;
                    else if (cnt == 0)
                        f[i][j] = 1;
                    else
                        f[i][j] = f[i-1][j];
                }
                //cout << i << ' ' << j << ' ' << f[i][j] << endl;
            }
        return f[len1][len2] <= 0 ? 0 : f[len1][len2];
    }
};
