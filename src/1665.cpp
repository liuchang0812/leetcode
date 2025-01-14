class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>&a, vector<int>& b) {
            int delta1 = a[1] - a[0];
            int delta2 = b[1] - b[0];
            if (delta1 == delta2) {
                return (a[1] > b[1]);
            }
            return delta1 > delta2;
            //return (delta1 == delta2) ? (a[1] >= b[1]) : (delta1 >= delta2);
        });

        //for (auto& p : tasks) {
        //    cout << p[0] << ' ' << p[1] << endl;
        //}

        int remain = 0;
        int ans = 0;
        for (auto& p : tasks) {
            auto mini = p[1];
            auto cost = p[0];
            if (remain >= mini) {
                remain -= cost;
            } else {
                ans += (mini - remain);
                remain = (mini - cost);
            }
        }

        return ans;
    }
};