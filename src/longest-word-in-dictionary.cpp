class Solution {
public:
    bool isOk(map<string, bool>& exists, string s) {
        for (int i=1; i<s.size(); ++i)
            if (exists[s.substr(0, i)] == false) return false;
        return true;
    }
    string longestWord(vector<string>& words) {
        map<string, bool> exists;
        for (auto& i:words) exists[i] = true;
        sort(words.begin(), words.end());
        
        int maxL = 0;
        string ans; 
        for (auto& i : words) {
            //cout << i << endl;
            if (i.size() <= maxL) continue;
            if (isOk(exists, i)) {
                maxL = i.size();
                ans = i;
                //cout << "ok " << i << endl;
            }
        }
        return ans;
    }
};
