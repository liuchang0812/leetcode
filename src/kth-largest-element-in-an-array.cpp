class Solution {
public:
    int kth(int left, int right, int k, vector<int>& nums)
    {
		int low = left, v = nums[left];
		int _left = left, _right = right;
		if (left >= right)
			return nums[left];
		while (_right > _left)
		{
			while (nums[_right] <= v && _right > _left)
				_right--;
			nums[_left] = nums[_right];
			
			while (nums[_left] >= v && _left < _right)
				_left ++;
			nums[_right] = nums[_left];	
		}
		
		nums[_left] =  v;
		if (_left+1 == k) return v;
		else if (_left < k)
			return kth(_left+1, right, k, nums);
		else
			return kth(left, _left-1, k, nums);
		
    }
    int findKthLargest(vector<int>& nums, int k) {
        return kth(0, nums.size()-1, k, nums);
    }
};
