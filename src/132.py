class Solution:
    def minCut(self, s: str) -> int:
        
        @cache
        def ispal(i, j):
            if j < i:
                return True

            if i == j:
                return True
            
            return s[i] == s[j] and ispal(i+1, j-1)
        
        @cache
        def dfs(p):
            if p >= len(s):
                return 0
            
            res = 3000
            for i in range(p, len(s)):
                if ispal(p, i):
                    res = min(res, 1+dfs(i+1))
            #print(f'{p=} {res=}')
            return res
        
        return dfs(0) - 1