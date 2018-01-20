class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // f[n][0] Nth could tail with 0 if true
        // f[n][1] Nth could tail with {10, 11} if true
        if (bits.size() == 1) true;
        
        int len = bits.size();
        int f[1005][2];
        memset(f, 0 ,sizeof f);
        if (bits[0] == 1) {
            f[0][0] = false;
            f[0][1] = false;
        } else {
            f[0][0] = true;
            f[0][1] = false;
        }
        
        if (bits[1] == 1) {
            
            f[1][0] = false;
            if (bits[0] == 1) f[1][1] = true;
            else f[1][1] = false;
        } else {
            f[1][0] = true;
            
            if (bits[0] == 0) {
                f[1][1] = false;
            } else {
                f[1][1] = true;
            }
        }
        for (int i=2; i < bits.size(); ++i)
        {
            f[i][0] = false;
            f[i][1] = false;
            
            if (bits[i] == 1 ) {
                if (bits[i-1] == 1 && (f[i-2][0] || f[i-2][1])) f[i][1] = true;
            } else {
                // bits[i] == 0
                if (f[i-1][0] || f[i-1][1]) f[i][0] = true;
                if (bits[i-1] == 1 && (f[i-2][0] || f[i-2][1])) f[i][1] = true;
            }
        }
        return f[bits.size()-1][1] == false;
    }
};
