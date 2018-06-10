class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        sort(hand.begin(), hand.end());
        map<int, int> cnt;
        for (auto i : hand)
            cnt[i] ++;
        set<int> num;
        for (auto i:hand)
            num.insert(i);
        
        for (int i:num) {
            while (cnt[i] != 0) {
                 bool lgAll=true;
                 for (int j=0; j<W; ++j)
                     if (cnt[i+j] <= 0) {
                        lgAll = false;
                        break;
                     }
                 if (lgAll) {
                     for (int j=0; j<W; ++j)
                         cnt[i+j] --;
                 } else 
                     return false;
            }
        }
        return true;
    }
};
