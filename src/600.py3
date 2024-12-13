class Solution:
    def findIntegers(self, n: int) -> int:
        n = bin(n)[2:]
        ln = len(n)
        print(n)

        @cache
        def dfs(i:int, prev: int, islimit:bool) -> int:
            if i == ln:
                return 1
            
            up = int(n[i]) if islimit else 1

            res = 0
            for x in range(up+1):
                if x == 1 and prev == 1:
                    continue
                res += dfs(i+1, x, islimit and x == up)
            return res
        return dfs(0, 0, True)