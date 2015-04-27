class Solution {
public:
    int f(int x)
    {
        int ans = 0;
        while (x != 0)
        {
            ans += (x%10) * (x%10);
            x /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        map<int, bool> occured;
        occured[n] = true;
        while (n != 1)
        {
            int tmp = f(n);
            if (tmp == 1) return true;
            if (occured[tmp]) return false;
            occured[tmp] = true;
            n = tmp;
        }
        return n == 1;
    }
};
