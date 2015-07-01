class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        ans = []
        f = lambda x, y:  str(x) if x == y else str(x) + "->" + str(y)
        
        if len(nums) == 0:
            return []
        st = nums[0]
        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] > 1:
                ans.append(f(st, nums[i-1]))
                st = nums[i]
        ans.append(f(st ,nums[-1]))
        return ans
            
