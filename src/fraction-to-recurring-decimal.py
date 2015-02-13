class Solution:
    # @return a string
    def fractionToDecimal(self, numerator, denominator):
        if numerator == 0:
            return "0"
        op = ""
        if numerator * denominator < 0:
            op = "-"
            
        numerator = abs(numerator)
        denominator = abs(denominator)
        num1 = "%d" % (numerator /  denominator)
        numerator = numerator % denominator
        first_pos = dict()
        num2 = ""
        cur = 0
        pre = -1
        
        if numerator == 0:
            return op+"%s" % num1
            
        #while numerator < denominator:
        #    num2 = num2 + "0"
        #    numerator = numerator * 10
        #    cur = cur + 1
        first_pos[numerator] = -1
        
        while numerator != 0:
            tmp = numerator * 10 % denominator   
            if tmp in first_pos:
                pre = first_pos[tmp]
                num2 = num2 + "%d"%(numerator * 10 /  denominator)
                cur = cur + 1
                return op+"%s.%s(%s)" % (num1, num2[:pre+1], num2[pre+1:])
            else:
                first_pos[tmp] = cur
            cur = cur + 1
            num2 = num2 + "%d"% (numerator * 10 / denominator)
            numerator = numerator * 10 % denominator
            
        if cur == 0:
            return op+"%s" % num1
        elif pre == -1:
            return  op+"%s.%s" % (num1, num2)
        else:
            return op+"%s.%s(%s)" % (num1, num2[:pre+1], num2[pre+1:])
            
            
