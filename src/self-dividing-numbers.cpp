class Solution {
public:
    bool isSelf(int x) {
        vector<int> digits;
        while (x > 0) 
        {
            digits.push_back(x%10);
            x /= 10;
        }
        for (auto i : digits) if (i==0 || x % i == 0) return false;
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i=left; i<=right;++i)
            if (isSelf(i)) ans.push_back(i);
        return ans;
    }
};
