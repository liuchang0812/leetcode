class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0;
        vector<int> nums;
        int tmp = num;
        while(tmp>0) {
            nums.push_back(tmp%10);
            tmp /= 10;
        }
        
        for (int i=nums.size()-1; i>=0; --i) 
            if (nums[i] == 6) { nums[i] = 9; break;}
        int jw = 1;
        for(int i=0;i<nums.size();++i) {
            ans += nums[i] * jw;
            jw*=10;
        }
        return ans;
    }
};
