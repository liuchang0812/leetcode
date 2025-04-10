class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        print(self.gao(start-1, limit, s))
        return self.gao(finish, limit, s) - self.gao(start-1, limit, s)

    def gao(self, finish: int, limit: int, s: str) -> int:

        sfinish = str(finish)
        n = len(str(finish))
        ns = len(s)

        if n < ns:
            return 0

        @cache
        def dfs(cur, islimit):
            if cur == n:
                return 1
            
            up = limit if not islimit else min(limit, int(sfinish[cur]))
            #print(f'{finish=} {cur=} {islimit=} {up=}')
            x = n - ns
            if cur >= x:
                p = cur - x
                mt = int(s[p]) 
                #print(f'{mt=} {up=}')
                if mt > up:
                    return 0
                else:
                    res = dfs(cur+1, islimit and int(s[p]) == int(sfinish[cur]))
                    #print(f'result {cur=} {islimit=} {res=}')
                    return res
            else:
                res = 0
                for i in range(0, up+1):
                    res += dfs(cur+1, islimit and i == int(sfinish[cur]))
                #print(f'result {cur=} {islimit=} {res=}')
                return res
        
        return dfs(0, True)
    

# 写的太丑了，有空整理一下