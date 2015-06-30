class Solution {
public:
    void majorityIter(const vector<int>& nums,int id, int ph1, int ph2, int cnt1, int cnt2)
    {
        if (id == nums.size()) return;
        int v = nums[id];
        
        if (cnt1 != 0 && v == ph1) majorityIter(nums, id+1, ph1, ph2, cnt1+1, cnt2);
        else if(cnt2 != 0&& v == ph2) majorityIter(nums, id+1, ph1, ph2, cnt1, cnt2+1);
        else if(cnt1 == 0) majorityIter(nums, id+1, v, ph2, 1, cnt2);
        else if(cnt2 == 0) majorityIter(nums, id+1, ph1, v, cnt1, 1);
        else majorityIter(nums, id+1, ph1, ph2, cnt1-1, cnt2-1);
    }
    
    int Cnt(const vector<int>& nums, int v)
    {
        int ans = 0;
        for (size_t i =0; i < nums.size(); ++i) ans += nums[i] == v;
        return ans;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int ph1, ph2;
        //majorityIter(nums,0, ph1, ph2, 0, 0);
        int cnt1 = 0, cnt2 = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int v = nums[i];
            
            if (cnt1 != 0 && v == ph1)
                cnt1 ++;
            else if (cnt2 != 0 && v == ph2)
                cnt2 ++;
            else if (cnt1 == 0)
            {
                ph1 = v;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                ph2 = v;
                cnt2 = 1;
            }
            else
            {
                cnt1 --;
                cnt2 --;
            }
        }
        vector<int> ans;
        if (cnt1 > 0 && Cnt(nums, ph1) > nums.size() / 3) ans.push_back(ph1);
        if (cnt2 > 0 && Cnt(nums, ph2) > nums.size() / 3) ans.push_back(ph2);
        return ans;
    }
};
