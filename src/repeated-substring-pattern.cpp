class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool ans;
        int len = s.size();
        for (int i=1; i<=len/2; ++i)
        {
            bool flag = true;
            if (len % i) continue;
            for (int j=0; j<i; ++j) {
                int k = 0;
                char c = s[j];
                flag = true;
                while (k*i +j < len) {
                    if (s[k*i+j] != c) {
                       flag = false;
                       break;   
                    }
                    ++k;
                }
                if (!flag) break;
            }
            if (flag) return true;
        }
        return false;
    }
};
