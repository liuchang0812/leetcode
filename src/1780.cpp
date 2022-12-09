class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            int md = n % 3;
            if (md != 0 && md != 1) return false;
            n = n / 3;
        }
        return true;
    }
};
