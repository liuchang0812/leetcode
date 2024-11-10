
class Solution:
    def num1(self, num):
        words = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        return words[num]

    def num3(self, num):
        res = ""
        hd = num // 100
        if hd > 0:
            res = self.num1(hd) + " " + "Hundred"
        
        num = num % 100
        if num == 0:
            return res

        if num < 20:
            res = res + " " + self.num1(num)
            return res
        
        words = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        res = res + " " + words[num // 10]
        if num % 10 != 0:
            res = res + " " + self.num1(num % 10)
        return res
    
    def numberToWords(self, num):
        if num == 0:
            return "Zero"
    
        #suff = ["Billion", "Million", "Thousand", ""]
        suff = ["", "Thousand", "Million", "Billion"]
        nums = []
        while num != 0:
            nums.append(num % 1000)
            num /= 1000
        
        res = ""
        for i in range(len(nums)):
            if nums[i] == 0:
                continue
            s = self.num3(nums[i])
            res = s  + " " + suff[i] + " " + res
        return ' '.join(res.split())
        #return res.strip()
        
