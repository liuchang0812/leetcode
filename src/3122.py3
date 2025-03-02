class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        @cache
        def dfs(col, num):
            if col == m:
                return 0
            
            cnt = 0
            for i in range(n):
                cnt += (grid[i][col] != num)
            
            minv = 1000000
            for i in range(0, 10):
                if i == num:
                    continue
                minv = min(minv, dfs(col+1, i))
            return cnt + minv
        
        return min(dfs(0, i) for i in range(0, 10))