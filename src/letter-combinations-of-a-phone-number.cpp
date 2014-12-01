class Solution {
public:
    vector<string> anses;
    string ans;
    string dig2string(char c) {
        switch(c) {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
        }
    }
    
    void dfs(int deep,string& digits, int target) {
        if (deep == target) anses.push_back(ans);
        else {
            string s = dig2string(digits[deep]);
            for (int i=0; i < s.size(); i++) {
                ans[deep] = s[i];
                dfs(deep+1, digits, target);
            }
        }
    }                            
    vector<string> letterCombinations(string digits) {
        ans.resize(digits.size());
        dfs(0, digits, digits.size());
        return anses;
    }
    

};
