class Solution {
public:
          int cache[500][500];
            int f[500][500];
    
    int dfs(const string& s, int l, int r) {
        //cout << l << ' ' << r << endl;
       if (cache[l][r] != -1)
           return cache[l][r];
        
        //cout << "DEBUG" << endl;
        int ans = INT_MAX;
        if (l >= r) ans = 0;
        else if (s[l] == s[r]) ans = dfs(s,  l+1, r-1);
        else {
            ans = min(ans, dfs(s,  l+1, r)+1);
            ans = min(ans, dfs(s,  l, r-1)+1);
        }
        
        cache[l][r] = ans;
        f[l][r] = ans;
        //cout << "l r ans: " << l << ' ' << r << ' ' << ans << endl;
        return ans;
    }
    int minInsertions(string s) {

        for(int i=0;i<500;++i)
            for(int j=0;j<500;++j)
                cache[i][j] = -1;
        
        return dfs(s, 0, s.size()-1);
    }
};
