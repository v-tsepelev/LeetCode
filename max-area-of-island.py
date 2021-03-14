from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        land = []
        def area(i, j: int) -> int:
            if not (0 <= i < len(grid) and 0 <= j < len(grid[0]) and (i,j) not in land and grid[i][j] == 1):
                return 0
            else:
                land.append((i,j))
                return (1 + area(i, j-1) + area(i, j+1) + area(i-1, j) + area(i+1, j))
        return max(area(i, j) for i in range(len(grid)) for j in range(len(grid[0])))
