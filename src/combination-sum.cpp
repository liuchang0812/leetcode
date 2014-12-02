class Solution {
public:
    map<int, int> cnt;
    vector<int> key;
    vector<vector<int> > anses;
    map<int, int> ans;
    void dfs(int deep, int maxdeep, int cur, int target) {
    	//cout << deep << ' ' << cur << endl;
        
        if (cur > target) return;
        if (cur == target) {
            vector<int> tmpans;
            for(map<int,int>::iterator p=ans.begin(); p!=ans.end(); p++)
            {
                if (p->second != 0)
                {
                    for (size_t i=0; i<p->second; i++) tmpans.push_back(p->first);
                }
            }
            anses.push_back(tmpans);
            return;
        }
        if (deep == maxdeep) return;
        for (size_t i=0; i <= (target - cur) / key[deep] ; i++) {
            if (key[deep] * i + cur <= target) {
                ans[key[deep]] = i;
                dfs(deep+1, maxdeep, cur + key[deep]*i, target);
                ans[key[deep]] = 0;
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        for (size_t i=0; i<candidates.size(); ++i)
            cnt[candidates[i]] ++;
        for (map<int, int>::iterator p=cnt.begin(); p!=cnt.end(); p++)
            key.push_back(p->first);
        dfs(0, key.size(), 0, target);
        return anses;
    }
};
