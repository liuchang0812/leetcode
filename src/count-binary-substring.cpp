class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> f;
        char cur = s[0];
        int curLen = 1;
        
        for (int i=1;i < s.size(); ++i)
        {
            if (s[i] == cur) curLen ++;
            else {
                cur = s[i];
                f.push_back(curLen);
                curLen = 1;
            }
        }
        f.push_back(curLen);
        for (auto i:f) cout << i << ' ' ; cout << endl;
        int ans = 0;
        
        for (int i=0; i < f.size()-1; ++i) {
            ans += min(f[i], f[i+1]);
        }
        return ans;
    }
};
