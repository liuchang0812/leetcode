class Solution {
public:
    vector<int> chooseK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n) return nums;

        int drop = n - k;

        vector<int> res;

        for (int i=0; i<nums.size(); ++i) {
            if (drop <= 0) {
                res.push_back(nums[i]);
                continue;
            }

            int j = res.size() - 1;
            while (j >= 0 && drop > 0) {
                if (res[j] < nums[i]) {
                    -- drop;
                    res.pop_back();
                    --j;
                } else {
                    break;
                }
            }
            if (res.size() + 1 <= k)
                res.push_back(nums[i]);
            else
                drop --;
        }
        return res;
    }

    bool compare(const vector<int>& n1, int i,  const vector<int>& n2, int j) {

        while (i < n1.size() && j < n2.size()) {
            if (n1[i] != n2[j]) return n1[i] > n2[j];
            ++i;
            ++j;
        }
        return n1.size() - i > (n2.size() - j) ;

    }
    vector<int> merge(const vector<int>& n1, const vector<int>& n2) {
        int len = n1.size() + n2.size();

        vector<int> res;

        int i,j;
        i = j = 0;
        for (int k=0; k<len; ++k) {
            if (i >= n1.size()) {
                res.push_back(n2[j++]);
            } else if (j >= n2.size()) {
                res.push_back(n1[i++]);
            } else {
                if (compare(n1, i, n2, j)) {
                    res.push_back(n1[i++]);
                } else {
                    res.push_back(n2[j++]);
                }
            }  
        }

        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for (int i=0; i<=k; ++i) {
            int i2 = k-i;
            cout << i << ' ' << i2 << ' ' << nums1.size() << ' ' << nums2.size() << endl;
            if (i > nums1.size()) continue;
            if (i2 > nums2.size()) continue;
            auto r1 = chooseK(nums1, i);
            auto r2 = chooseK(nums2, i2);
             for (auto r : r1) cout << r << ' ' ; cout << endl;
            for (auto r : r2) cout << r << ' ' ; cout << endl;
            auto res = merge(r1, r2);
            for (auto r : res) cout << r << ' ' ; cout << endl;
            if (compare(res, 0, ans, 0)) {
                ans = res;
            }
        }

        return ans;
    }
};
