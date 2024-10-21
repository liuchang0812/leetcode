class Solution:
    def minCut(self, s: str) -> int:
        
        n = len(s)
        g = [[True] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = (s[i] == s[j]) and g[i + 1][j - 1]

        @cache
        def dfs(i):
            if i < 0:
                return 0
            if g[0][i]:
                return 0
            else:
                v = 3000
                for j in range(i):
                    if g[j+1][i]:
                        v = min(v, dfs(j)+1)
                return v
        return dfs(len(s)-1)
