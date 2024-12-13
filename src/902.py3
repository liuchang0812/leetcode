class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        
        ns = str(n)
        nl = len(ns)

        @cache
        def dfs(i:int, islimit:bool, isnum: bool):
            if i == nl:
                return isnum
            
            up = ns[i] if islimit else '9'
            #print(f'dfs: {i=} {up=} {islimit=} {isnum=}')
            res = 0
            if not isnum:
                res += dfs(i+1, False, False)

            for x in digits:
                if x > up:
                    continue
                
                res += dfs(i+1, islimit and x == ns[i], True)
            
            return res
        
        return dfs(0, True, False)


