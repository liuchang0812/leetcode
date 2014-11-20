class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        a,b = 1,1
        for i in range(1,n):
            a,b = a+b,a
            
        return a
        
