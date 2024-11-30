class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        
        @cache
        def dfs(status:int, cur:int) -> int:
            if cur >= len(nums):
                return 0

            maxv = 0
            for i in range(0, 2*numSlots):
                bt = (1<<i)
                if (status & bt) :
                    continue
                else:
                    maxv = max(maxv, dfs(status | bt, cur + 1) + (nums[cur] & ((i // 2)+1)))
            #print(bin(status), cur, maxv)
            return maxv
        return dfs(0, 0)
