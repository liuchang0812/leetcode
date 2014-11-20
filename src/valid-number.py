class Solution:

    # @param s, a string

    # @return a boolean



    def isDigitals(self, s):
        return s.isdigit()


    def isInter(self, s):
        if s=='':
            return True
        pos = s.find('e')
        if pos == -1:
            return self.isDigitals(s)
        else:
            if s[:pos] == "" and s[pos+1:] == "":
                return False
            return self.isDigitals(s[:pos]) and self.isDigitals(s[pos+1:])

    def isNumber2(self, s):
        if s == "":
            return False
            
        if s[0] == '-' or s[0] == '+':
            return self.isNumber2(s[1:])
            
        pos = s.find('.')
        if pos == -1:
            return self.isInter(s)
        else:
            if s[:pos] == "" and s[pos+1:] == "":
                return False
            return   self.isInter(s[:pos]) and self.isInter(s[pos+1:])

    def isNumber(self, s):
        s = s.strip()
        return self.isNumber2(s)
