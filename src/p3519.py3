def tobase(x, b):
    if x == 0:
        return '0'
    res = ''
    while x != 0:
        res = str(x%b) + res
        x = x // b
    return res

class Solution:
    def f(self, v: str, b:int) -> int:
        vv = tobase(int(v), b)
        #print(vv)
        @cache
        def dfs(cur, islimit, start):
            if cur == len(vv):
                return 1
            
            up = int(vv[cur])+1 if islimit else b
            res = 0
            for x in range(start, up):
                res += dfs(cur+1, islimit and x == int(vv[cur]), x)
            #print(f'{cur=} {islimit=} {start=} {up=} {res=}')
            return res
        return dfs(0, True, 0)

    def countNumbers(self, l: str, r: str, b: int) -> int:
        #print(self.f(l, b))
        #print(self.f(r, b))
        return (self.f(r, b) - self.f(str(int(l)-1), b))%(10**9+7)