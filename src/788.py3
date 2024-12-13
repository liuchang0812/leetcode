class Solution:
    def rotatedDigits(self, n: int) -> int:
        ns = str(n)
        nl = len(ns)

        can = [True, True, True, False, False, True, True, False, True, True]
        change = [False, False, True, False, False, True, True, False, False, True]

        @cache
        def dfs(i:int, islimit:bool, isnum:bool) -> int:
            if i == nl:
                return isnum

            up = int(ns[i]) if islimit else 9

            res = 0
            for x in range(up+1):
                if not can[x]:
                    continue
                
                if change[x]:
                    res += dfs(i+1, islimit and x == up, True)
                else :
                    res += dfs(i+1, islimit and x == up, isnum)

            return res

        return dfs(0, True, False)