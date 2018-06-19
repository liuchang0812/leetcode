class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
	int left = INT_MAX;
	int right = -1;

	for (int i=0; i<nums.size(); ++i) 
		for (int j=0; j<i; ++j) {
			if (nums[j] > nums[i]) {
				left = min(j, left);
				right = i;
				break;
			}
		}
	if (left == INT_MAX) return 0;
	else return right - left + 1;
    }
};
