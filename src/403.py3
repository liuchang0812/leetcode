class Solution:
    def canCross(self, stones: List[int]) -> bool:
        target = stones[len(stones)-1]
        hset = set(stones)

        @cache
        def dfs(cur, k):
            print(f'{cur=} {k=}')
            if cur == target:
                return True  

            if cur > target:
                return False
            
            if not cur in hset:
                return False

            res = False
            for i in range(k-1, k+2):
                if i <= 0:
                    continue
                n = cur + i  
                res = res or dfs(n, i)
            
            return res
        
        return dfs(stones[0], 0)