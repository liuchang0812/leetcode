class Solution:
    # @return a boolean
    
    def ParenPair(self, lf, rg):
        return lf == '(' and rg == ')' or \
               lf == '[' and rg == ']' or \
               lf == '{' and rg == '}'
               
    def isValid(self, s):
        st = list()
        for char in s:
            if char in ['(', '{', '[' ]:
                st.append(char)
            elif char in [ ')', '}', ']']:
                if len(st) == 0:
                    return False
                lf = st.pop()
                if not self.ParenPair(lf, char):
                    return False
            else:
                pass
        return len(st) == 0

s = Solution()
print s.isValid("(((()))[])")                
print s.isValid("[[[[)]]]]")
