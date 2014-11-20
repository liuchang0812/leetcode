# Definition for a point
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    
    def one_line(self, pnt_i, pnt_j, pnt_k):
        if pnt_i.x == pnt_j.x and pnt_j.x == pnt_k.x:
            return True;
        if pnt_i.y == pnt_j.y and pnt_j.y == pnt_k.y:
            return True;
        return (pnt_j.y - pnt_i.y) * (pnt_k.x - pnt_j.x) == (pnt_j.x - pnt_i.x)*(pnt_k.y - pnt_j.y)
        
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        cnt = dict()
        pnt = list()
        ans = 0
        for point in points:
            try:
                cnt[point] = cnt[point] + 1
                ans = max(ans, cnt[point])
            except KeyError as e:
                cnt[point] = 1
                pnt.append(point)
        print(ans)
        for i in range(len(pnt)):
            for j in range(i+1, len(pnt)):
                pnt_i = pnt[i]
                pnt_j = pnt[j]
                tmp = cnt[pnt_i] + cnt[pnt_j]
                
                for k in range(j+1, len(pnt)):
                    if self.one_line(pnt_i, pnt_j, pnt[k]):
                        tmp = tmp + cnt[pnt[k]]
                
                ans = max(ans, tmp)
        return ans;
