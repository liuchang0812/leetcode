class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
            ana = dict()
            for str in strs:
                sstr = ''.join(sorted(str))
                try:
                    ana[sstr].append(str)
                except KeyError:
                    ana[sstr] = []
                    ana[sstr].append(str)
            ans = []
    
            for i in ana:
                v = ana[i]
                if len(v) > 1:
                    for x in v: ans.append(x)
            return ans
