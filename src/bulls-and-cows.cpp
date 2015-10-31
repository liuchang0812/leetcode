class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bull = 0;
        for (size_t i=0; i<secret.size(); ++i)
            if (secret[i] == guess[i])
                bull ++;
        
        int a[256], b[256];
        memset(a, 0, sizeof a); memset(b, 0, sizeof b);
        for (char c:secret) a[c] ++;
        for (char c:guess) b[c] ++;
        int len = 0;
        for (int i=0; i < 256; ++i) len += min(a[i], b[i]);
        int cows = len - bull;
        char ans[100];
        sprintf(ans, "%dA%dB", bull, cows);
        return string(ans);
    }
};
