class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        if (n == 0) return "A";
        while (n > 0) 
        {
            if ( n % 26 == 0) 
            {
                ans = "Z" + ans;
                n --;
            }
            else 
            {
                ans = char((n%26) + 'A' - 1) + ans;
            }
            n /= 26;
        }
        return ans;
    }
};
