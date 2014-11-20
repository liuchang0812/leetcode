class Solution:
    # @return a string
    def countAndSay(self, n):
        pre = "1"
        for i in range(n-1):
            pre = self.f(pre)
        return pre
    
    def f(self, s):
        ans = ""
        pre = s[0]
        cur = 1
        for c in s[1:]:
            if c == pre:
                cur = cur + 1
            else:
                ans = ans + str(cur) + pre
                cur = 1
                pre = c
        
        if cur > 0:
            ans = ans + str(cur) + pre
        return ans
