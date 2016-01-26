class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(); 
        int len2 = s2.size();
        int len3 = s3.size();
        
        if (len1 + len2 != len3) return false;
        // f[i][j] = f[i-1][j] && s1[i] == s3[i+j]
        //           f[i][j-1] && s2[j] == s2[i+j]
        
        bool f[len1+2][len2+2];
        f[0][0] = true;
        
        for (int i=0; i<= len1; ++i)
            for (int j=0; j<= len2; ++j)
            {
                if (i==0 && j==0) continue;
                
                int ret = false;
                if (i-1 >= 0)
                    ret = f[i-1][j] && s1[i-1] == s3[i+j-1];
                if (j-1 >= 0)
                    ret = ret || (f[i][j-1] && s2[j-1] == s3[i+j-1]);
                f[i][j] = ret;
            }
        return f[len1][len2];
    }
};
