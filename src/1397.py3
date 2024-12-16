class Solution:
    def next(self, evil: str):
        res = [0] * len(evil)

        j = 0
        for i in range(1, len(evil)):
            k = res[i-1]
            while k > 0 and evil[k] != evil[i]:
                k = res[k-1]
            
            if evil[k] == evil[i]:
                res[i] = k+1
            else:
                res[i] = k
        return res




    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        nt = self.next(evil)
        print(f'{nt=}')
        evil_size = len(evil)

        @cache
        def dfs(i:int, pos:int, islimit:bool, ss:str)->int:
            if pos == evil_size:
                return 0
            if i == n:
                return 1
            up = ss[i] if islimit else 'z'

            res = 0
            for j in range(ord('a'), ord(up)+1): 
                x = chr(j)

                k = pos
                #print(f'{k=} {x=} {s=} ', type(k))
                while k > 0 and evil[k] != x:
                    k = nt[k-1]

                if evil[k] == x:
                    res += dfs(i+1, k+1, islimit and x == up, ss)
                else:
                    res += dfs(i+1, 0, islimit and x == up, ss)
            #print(f'{i=} {n=} {pos=} {islimit=} {res=}')

            return res%1000000007
        v2 = dfs(0, 0, True, s2)
        dfs.cache_clear()
        v1 = dfs(0, 0, True, s1)

        print(v1, v2)
        return (v2-v1+int(evil not in s1))  % (1000000007)