class Solution:
    def countSpecialNumbers(self, n: int) -> int:

        ns = str(n)
        nl = len(ns)

        @cache
        def dfs(i:int, pre:int, valid:int, islimit:bool, isnum: bool):
            if i == nl:
                return valid and isnum
            
            up = int(ns[i]) if islimit else 9
            res = 0
            if not isnum:
                res = dfs(i+1, 0, False, False, False)
            
            low = 0 if isnum else 1
            for x in range(low, up+1):
                if valid or (pre & (1<<x)):
                    res += dfs(i+1, pre | (1<<x), True, islimit and x == up, True)
                else:
                    res += dfs(i+1, pre | (1<<x), valid, islimit and x == up, True)
            #print(f"dfs {i=} {pre=} {valid=} {islimit=} {isnum=} {res=}")
            return res
        
        return n - dfs(0, 0, False, True, False)