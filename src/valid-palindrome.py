class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        s =  filter(lambda x: str.isalnum(x), s).lower()
        return s== s[::-1]
