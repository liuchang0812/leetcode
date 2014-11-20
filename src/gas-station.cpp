class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int ans = -1;
        for (int start_position = 0; start_position < gas.size(); start_position ++)
        {
            int cur = 0, fail = 0;
            for (int i = 0;i < gas.size();i ++)
            {
                int now_position = (start_position + i) % gas.size();
                cur += gas[now_position];
                cur -= cost[now_position];
                if ( cur < 0)
                {
                    fail = 1;
                    if (now_position > start_position)
                        start_position = now_position;
                    break;
                }
            }
            if (fail == 0)
            {
                ans = start_position;
                break;
            }
        }
        return ans;
    }
};
