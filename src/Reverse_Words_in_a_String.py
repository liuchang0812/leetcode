import unittest

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        # strip string
        words = s.strip().split()[::-1]
        words = map(lambda x: x+" ", words)
        return ''.join(words).strip()

def reverseWordsTest(unittest.TestCase):
    def __init__(self):
        self.solution = Solution()
    
    def test_blank(self):
        input_str = ''
        unittest.assertEqual(self.solution.reverseWords(input_str), "")
    
    def test_strip(self):
        input_str = ' a b '
        unittest.assertEqual(self.solution.reversWords(input_str), 'b a')
        
    def test_multiblank(self):
        input_str = ' a  b'
        unittest.assertEqual(self.solution.reversWords(input_str), 'b a')
    
    def test_tabblank(self):
        input_str = '    a  b'
        unittest.assertEqual(self.solution.reversWords(input_str), 'b a')

if __name__ == "__main__":
    unittest.main()
        
