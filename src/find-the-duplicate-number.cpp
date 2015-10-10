class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size()-1;
        
        while (r >= l)
        {
            int m = l + (r-l)/2;
            int cnt = 0;
            for(int i:nums)
                cnt += (i<=m);
            if (cnt <= m)
                l = m+1;
            else
                r = m-1;
        }
        return l;
    }
};
