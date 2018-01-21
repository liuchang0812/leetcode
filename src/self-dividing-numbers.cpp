class Solution {
public:
    bool isSelf(int x) {
        vector<int> digits;
        int y = x;
        while (x > 0) 
        {
            digits.push_back(x%10);
            cout << x % 10 << endl;
            x /= 10;
            
        }
        for (auto i : digits) 
            if (i==0 || y % i != 0) return false;
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i=left; i<=right;++i)
            if (isSelf(i)) ans.push_back(i);
        return ans;
    }
};
