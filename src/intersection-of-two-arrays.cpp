class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> duplicated;
        vector<int> ret;
        for (auto i: nums1)
        {
            if (duplicated[i]) continue;
            duplicated[i] = true;
            for (auto j: nums2)
            {
                if (j == i) {
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};
