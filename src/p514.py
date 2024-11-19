class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        n = len(ring)

        @cache
        def dfs(cur: int, pos: int) -> int:
            if cur == len(key):
                return 0
            
            ans = 1000000000

            for i in range(n):
                if ring[i] == key[cur]:
                    d = abs(pos-i)
                    ans = min(ans, dfs(cur+1, i) + min(d, n-d) + 1)
            
            return ans

        return dfs(0, 0)
