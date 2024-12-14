class Solution:
    def fun(self, ns: str, min_sum: int, max_sum: int) -> int:
        nl = len(ns)

        @cache
        def dfs(i:int, sum:int, islimit:bool, isnum:bool):
            if i == nl:
                return isnum and sum >= min_sum and sum <= max_sum
            
            up = int(ns[i]) if islimit else 9
            low = 0 if isnum else 1

            res = 0
            if not isnum:
                res = dfs(i+1, sum, False, False)
            
            for x in range(low, up+1):
                res += dfs(i+1, sum+x, islimit and x==up, True)
            #print(f'dfs {i=} {sum=} {islimit=} {isnum=} {res=}')
            return res
        
        return dfs(0, 0, True, False)
        
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        print(self.fun(num2, min_sum, max_sum))
        print(self.fun(str(int(num1) - 1), min_sum, max_sum))
        return (self.fun(num2, min_sum, max_sum) - self.fun(str(int(num1) - 1), min_sum, max_sum)) % (10**9 + 7) 