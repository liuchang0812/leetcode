class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i, j):
            if i < 0:
                if j < 0:
                    return True
                elif p[j] == '*':
                    return dfs(i, j-1)
                else:
                    return False
            elif i < 0 or j < 0:
                return False
            
            if s[i] == p[j]:
                return dfs(i-1, j-1)
            
            if p[j] == '?':
                return dfs(i-1, j-1)
            
            if p[j] == '*':
                return dfs(i, j-1) or dfs(i-1, j) or dfs(i-1, j-1)
            
            return s[i] == p[j]
        
        return dfs(len(s)-1, len(p)-1)
