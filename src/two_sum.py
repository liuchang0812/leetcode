class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        indexs = {}
        for i in range(len(num)):
            indexs[num[i]] = i + 1
        for v in range(len(num)):
            if indexs.has_key(target - num[v]) == True and indexs[target - num[v]] != v + 1:
                return (v+1, indexs[target - num[v]])
        # never run here
        return (0,0)
        
        
```
直接n^2暴力会超时，所以要nlogn才可以，使用python内置的dict来标记是否存在某值
```
