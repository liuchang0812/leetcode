class Solution:
    # @return an integer
    def f(self,str):
        str = str.strip()
        if len(str) == 0:
            return str
        x = ''
        if str[0] == '+' or str[0] == '-' or str[0] in string.digits:
            x = str[0]
            str = str[1:]
        else:
            return ''
            
        for s in str:
            if  s in string.digits:
                x += s
            else:
                break
        return x
        
    def atoi(self, str):
        int_max = 2147483647
        int_min = -2147483648
        str = self.f(str)
        try:
            return max(int_min,min(int(str), int_max))
        except :
            return 0
