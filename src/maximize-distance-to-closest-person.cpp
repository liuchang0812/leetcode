class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N = seats.size();
        int ans = 0;
        int pre = 0;
        bool first = true;
        int last = 0;
        for (int i=0; i<N; ++i) {
            if (seats[i])
            {
                if (first)  {
                    ans = max(ans, i);
                    first = false;
                }
                else {
                    int dis = i - pre;
                    ans = max(ans, dis/2);
              
                }
                pre = i;
                last = i;
            }
        }
        cout << ans << ' ' << last << endl;
        ans = max(ans, N - 1 - last);
        return ans;
        
    }
};
