class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        n = len(target)
        @cache
        def isprefix(ss):
            for word in words:
                if word.startsWith(ss):
                    return True
            return False

        @cache
        def dfs(i:int, j:int) -> int:

            if i > j:
                return 0
            
            s = target[i:j]

            if isprefix(s):
                return 1
            
            res = 100
            for k in range(i, j):
                ss = target[i, k]
                if isprefix(ss):
                    res = min(res, dfs(k+1, j))
            
            return res+1
        return dfs(0, n-1)


Solution sol

print(sol.minValidStrings(["abc","aaaaa","bcdef"], "aabcdabc"))

