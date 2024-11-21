class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:

        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i > j:
                return 0

            if i == j:
                return (k + 1) * (k + 1)

            res = (k + 1) * (k + 1) + dfs(i + 1, j, 0)

            for m in range(i + 1, j + 1):
                if boxes[i] == boxes[m]:
                    res = max(res, dfs(i + 1, m - 1, 0) + dfs(m, j, k + 1))
            # print(i,j,k,res)
            return res

        return dfs(0, len(boxes) - 1, 0)
