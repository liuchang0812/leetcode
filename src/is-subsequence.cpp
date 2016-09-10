class Solution {
public:
    bool isSubsequence(string s, string t) {
            int i=0;
            int pre=0;
            for(; i<s.size();++i)
            {   
                int j=pre;
                for (;j < t.size(); ++j)
                {
                    if (s[i] == t[j])
                    {
                        pre = j+1;
                        break;
                    }
                }
                if (j == t.size()) return false;
            }
            return i == s.size();
    }
};
