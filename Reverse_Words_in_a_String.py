class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        # trip string
        words = s.strip().split()[::-1]
        words = map(lambda x: x+" ", words)
        return ''.join(words).strip()
