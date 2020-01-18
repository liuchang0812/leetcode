class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size()%k) return false;
        //sort(nums.begin(), nums.end());
        multiset<int> s;
        for (auto i:nums) s.insert(i);
        while (!s.empty()) {
            auto p = s.begin();
            int v = *p;
            for (int j=0;j<k;++j) {
                auto p2 = s.find(v+j);
                if (p2 != s.end())
                    s.erase(p2);
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
