class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        nums = [1] + nums + [1]
        #print(nums)

        @cache
        def dfs(i:int, j:int) -> int:
            if j <= i+1:
                return 0
            res = 0
            for k in range(i+1, j):
                res = max(res, dfs(i, k) + dfs(k, j) + nums[i] * nums[k] * nums[j])
            return res
        return dfs(0, n+1)
