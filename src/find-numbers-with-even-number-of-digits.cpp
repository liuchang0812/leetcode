class Solution {
public:
    int getSize(int x) {
        int ans = 0;
        int pw = 1;
        while (pw <= x) {
            ++ans;
            pw *= 10;
        }
        return ans;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto i:nums) {
            if (getSize(i)%2==0) {
                ++ ans;
                cout << i << endl;
            }
        }
        return ans;
    }
};
