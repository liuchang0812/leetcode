class Solution:
    def maxValue(self, nums: List[int], k: int) -> int:
        
        @lru_cache(maxsize==3000000)
        def dfs(left, right, remain, cur) -> int:

            if remain == 0:
                v = left ^ right
                #print(f'{left=} {right=}  {cur=} {v=}')
                return left ^ right

            if cur >= len(nums) or remain < 0:
                return 0

            #print(f'dfs {left=} {right=} {remain=} {cur=} {nums[cur]=}')

            res = 0
            if remain > k:
                res = max(res, dfs((left | nums[cur]), right, remain-1, cur+1))
            
            if remain <= k:
                res = max(res, dfs(left, (right | nums[cur]), remain-1, cur+1))
            
            res = max(res, dfs(left, right, remain, cur+1))

            # print(f'{left=} {right=} {leftcnt=} {rightcnt=} {cur=} {v1=} {v2=} {v3=}')
            return res
        return dfs(0, 0, 2*k, 0)
