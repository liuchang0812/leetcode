class Solution {
public:
    using ll = long long;
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        ll sum = 0;
        sort(nums.begin(), nums.end());
        vector<ll> prefix_sum = {0};
        ll cur = 0;
        for (auto n : nums) {
            cur += n;
            prefix_sum.push_back(cur);
        }
        sum = cur;


        auto bsearch = [&](int v) {
            int l = 0;
            int r = nums.size();

            while (l + 1< r) {
                int m = (0ll + l + r) / 2;

                if (nums[m] > v) {
                    r = m;
                } else if (nums[m] < v) {
                    l = m;
                } else {
                    return m;
                }
            }
            return l;
        };

        vector<ll> ans;
        for (ll q : queries) {
            auto idx = bsearch(q);
            if (idx == 0 && nums[idx] > q) {
                ans.push_back(sum - (q*nums.size()));
                continue;
            }
            //cout << q << ' ' << idx << ' ' << nums[idx] << endl;
            ++idx;
            ans.push_back(q * idx - prefix_sum[idx] + (sum - prefix_sum[idx]) - (q * (nums.size() - idx)));
        }

        return ans;
    }
};