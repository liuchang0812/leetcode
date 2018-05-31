class Solution {
public:
    long long toInt(const string& s, int curPos, int i){
        long long ans = 0;
        for (int k = curPos;  k < i; ++k) {
            ans = ans * 10 + (s[k] - '0');
        }
        return ans;
    }
    
    void dfs(const string& s, int curPos, vector<int>& ans, vector<int>& ans2) {
        //cout << "current: " << curPos << endl;
        //for (auto i:ans) cout << i << ' ' ; cout << endl;
        if (curPos == s.size() && ans.size() >= 3) {
            cout << "OK" << endl;
            ans2 = ans;
            return;
        }
        if (curPos >= s.size()) return ;

        for (int i=curPos+1; i<=s.size(); ++i)
        {
            long long tryV = toInt(s, curPos, i);
            if (tryV == 0 && s[curPos] == '0' && i>curPos+1 && s[curPos+1] == '0') continue;
            if (tryV != 0 && s[curPos] == '0') continue;
            if (tryV >= INT_MAX) continue;
            if (ans.size() >= 2 && ans[ans.size()-1] + ans[ans.size()-2] != tryV) continue; 
            ans.push_back(tryV);
            dfs(s, i, ans, ans2);
            ans.pop_back();
        }
    }
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans1, ans2;
        dfs(S, 0, ans1, ans2);
        return ans2;
    }
};
