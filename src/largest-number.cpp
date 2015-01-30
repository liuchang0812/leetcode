class Solution {
public:
    string int2str(int num) {
        if (num == 0) return "0";
        else {
            string ans = "";
            while (num > 0) {
                ans = char(num % 10 + '0') + ans;
                num /= 10;
            }
            return ans;
        }
    }
    
    static bool SpecialCompare(const string& num1, const string& num2) {
        string s1, s2;
        s1 = num1 + num2;
        s2 = num2 + num1;
        return s1 > s2;
    }
    
    string largestNumber(vector<int> &num) {
        vector<string> sNum;
        for (int i = 0;i < num.size(); ++i)
            sNum.push_back(int2str(num[i]));
        sort(sNum.begin(), sNum.end(), SpecialCompare);
        string ans;
        for (size_t i=0; i<sNum.size(); i++)
            ans = ans + sNum[i];
        int prefixzero = 0;
        while (prefixzero < ans.size() && ans[prefixzero] == '0') prefixzero++;
        if (prefixzero == ans.size()) return "0";
        else return ans.substr(prefixzero);
    }
};
