class Solution {
public:
    vector<int> ans;
    vector<int> decompressRLElist(vector<int>& nums) {
        ans.clear();
        for (int i=0;i < nums.size(); i+=2) {
            int a = nums[i];
            int b = nums[i+1];
            for (int j=0; j<a;++j)
                ans.push_back(b);
        }
        return ans;
    }
};
