class Solution {
public:
    const int NO_MP = -1000;
    
    bool isIsomorphic(string s, string t) {
        int cnt1[256];
        int cnt2[256];
        
        for (size_t i=0; i<256; ++i)
        {
            cnt1[i] = NO_MP;
            cnt2[i] = 0;
        }
        for (size_t i=0; i<s.size(); i++)
        {
            int diff = t[i] - s[i];
            if (cnt1[s[i]] == NO_MP) {
                cnt1[s[i]] = diff;
                cnt2[t[i]] ++;
            }
            else
                if (diff != cnt1[s[i]]) return false;
        }
        for (int i = 0; i < 256; ++i)
            if (cnt2[i] > 1) return false;
        return true;
    }
};
