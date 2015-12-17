class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        if (n == 0) return 0;
        bool f[n][n] = {0};
        memset(f, 0, sizeof 0);
        
        int contains[n][26] = {0};
        memset(contains, 0, sizeof 0);
        for (int i = 0; i < n; ++i)
        {
            for (auto c:words[i])
            {
                contains[i][c-'a'] = 1;
            }
        }
        
        for (char i = 'a'; i <= 'z'; ++i)
        {
            vector<int> duplicates;
            
            for (int j=0; j<n; ++j)
            if (contains[j][i-'a'])
                duplicates.push_back(j);
            
            for (int j=0; j <duplicates.size(); ++j)
                for (int k=0; k<duplicates.size(); ++k)
                f[duplicates[j]][duplicates[k]] = 1;
        }
        int sizes[n];
        for (int i=0; i<n; ++i)
            sizes[i] = words[i].size();
            
        int ans = 0;
        for (int i=0; i < n; ++i)
            for (int j=0; j<n; ++j)
            {
                if (f[i][j] == 0 && i!=j)
                    ans = max(ans, int(sizes[i] * sizes[j]));
            }
        return ans;
    }
};
