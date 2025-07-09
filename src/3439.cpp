class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;

        int n = startTime.size();

        gaps.push_back(startTime[0]);
        for (int i=0; i<n-1; ++i) {
            gaps.push_back(startTime[i+1] - endTime[i]);
        }

        gaps.push_back(eventTime - endTime.back());

        //for (auto v : gaps) cout << v << ' ' ; cout << endl;
        int ans = 0;
        int cur = 0;
        for (int i=0; i<=k; ++i) cur += gaps[i];
        ans = cur;
        for (int i=k+1; i<gaps.size(); ++i) {
            cur = cur - gaps[i-k-1] + gaps[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};