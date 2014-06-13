class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        try:
            return len(s.split()[::-1][0])
        except IndexError,e:
            return 0
        
