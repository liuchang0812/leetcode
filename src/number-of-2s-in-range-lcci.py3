class Solution:
    def numberOf2sInRange(self, n: int) -> int:
        
        ns = str(n)
        nl = len(ns)

        @cache
        def dfs(i:int, sum:int, islimit:bool, isnum:bool):
            if i == nl:
                if isnum:
                    return sum
                else:
                    return 0
            
            up = int(ns[i]) if islimit else 9
            low = 0 if isnum else 1

            res = 0
            if not isnum:
                res = dfs(i+1, sum, False, False)
            
            for x in range(low, up+1):
                res += dfs(i+1, sum + (x == 2), islimit and x==up, True)
            #print(f'dfs {i=} {sum=} {islimit=} {isnum=} {res=}')
            return res
        return dfs(0, 0, True, False)