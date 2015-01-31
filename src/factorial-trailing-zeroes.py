class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        return sum(map(lambda x: n / (5**x) , range(1, 31)))
