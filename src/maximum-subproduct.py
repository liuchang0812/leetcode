class Solution:
    def maxProduct2(self, A):
        negs = sum(map(lambda x: x<0, A))
        if negs % 2 == 0:
            return reduce(lambda a,b: a*b, [1] + A)
        else:
            produ = reduce(lambda a,b: a*b, [1] + A)
            if len(A) == 1: return A[0]
            cur, ans = 1,0
            for i in A:
                if i < 0:
                    ans = max(ans, cur, produ / cur / i)
                cur = cur * i
            return ans

    def maxProduct(self, A):
        if len(A) == 1: return A[0]
        ans, pre, cur = 0, 0, 0
        for i, j in enumerate(A):
            if j == 0:
                if i > pre: ans = max(ans, self.maxProduct2(A[pre: i]))
                pre = i + 1
        if pre < len(A): ans = max(ans, self.maxProduct2(A[pre:]))
        return ans
