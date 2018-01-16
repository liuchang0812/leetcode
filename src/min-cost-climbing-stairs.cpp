class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // f[i] = min(cost[i] + f[i-1], cost[i] + f[i-2]);
        vector<int> f;
        f.push_back(cost[0]);
        f.push_back(cost[1]);
        for (int i=2; i<cost.size(); ++i)
            f.push_back(min(cost[i] + f[i-1], cost[i] + f[i-2]));
        return min(f[cost.size()-1], f[cost.size()-2]);
    }
};
