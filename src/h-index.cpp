class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int len = citations.size();
        
        int ans = len;
        while (ans)
        {
            auto p=lower_bound(citations.begin(), citations.end(), ans);
            int num = citations.end() - p;
            //cout << num << ' ' << ans << endl;
            if (num >= ans)
                return ans;
            ans --;
        }
        return 0;
    }
};
