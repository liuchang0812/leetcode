class Solution {
public:
    int wise(int x) {
        return (x == 2) ? 1: 2;
    }
    int magicalString(int n) {
        string s = "122";

        char str[100005];
        str[0] = 1;
        str[1] = 2;
        str[2] = 2;

        int cnt_ptr = 1;
        int chr_ptr = 2;
        int ans = 1;
        while (chr_ptr < n-1) {
            ++ cnt_ptr;
            int to_char = wise(str[chr_ptr]);

            for (int i=0; i<str[cnt_ptr]; ++i)
            {
                str[++chr_ptr] = to_char;
                ans += to_char == 1;
                // cout << to_char << endl;
                if (chr_ptr >= n-1) return ans;
            }
        }
         return ans;
    }
};
