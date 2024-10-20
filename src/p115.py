class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ans = 0
        md = 10**9+7
        @cache
        def dfs( i,  j):
            if j <0:
                return 1

            if i < 0 and j >= 0:
                return 0
            
            if s[i] != t[j]:
                return dfs(i-1, j)
            else:
                return (dfs(i-1, j-1) + dfs(i-1, j)) % md

        return dfs(len(s)-1, len(t)-1)
