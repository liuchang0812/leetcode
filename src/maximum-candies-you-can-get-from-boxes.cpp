class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        deque<int> Q;
        for(auto i:initialBoxes) Q.push_back(i);
        map<int, bool> opened;
        int ans = 0;
        while (!Q.empty()) {
            int box = Q.front(); Q.pop_front();
            if (opened[box]) continue;
            else {
                if (status[box] == 1) {
                    opened[box] = true;
                    ans += candies[box];
                    for (auto key: keys[box]) status[key] = 1;
                    for (auto box2:containedBoxes[box]) if (opened[box2]==false)Q.push_back(box2);
                } else {
                    // can't open
                    Q.push_back(box); // push back
                }
            }
            // check
            bool ans = false;
            for (auto p=Q.begin(); p!=Q.end(); ++p)
                if (status[*p]) ans = true;
            if (ans==false) break;
        }
        return ans;
    }
};
