class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto i:nums)
            ++ cnt[i];
        
        vector<pair<int, int>> num2cnt;
        for (auto i:cnt)
            num2cnt.push_back(make_pair(i.first, i.second));
        
        sort(num2cnt.begin(), num2cnt.end(), [](pair<int, int> x, pair<int, int> y){return x.second > y.second;});
        vector<int> ans;
        for (int i=0; i<k; ++i)
            ans.push_back(num2cnt[i].first);
        return ans;
    }
};
