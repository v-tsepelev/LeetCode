from typing import List

class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
          total_gold = 0
          m = len(grid)
          n = len(grid[0])
          for i in range(m):
               for j in range(n):
                    if grid[i][j] != 0:
                         visited = []
                         path_from_cell = self.searchForPath(m, n, i, j, grid, visited)
                         total_gold = max(total_gold, path_from_cell)
          return total_gold

    def searchForPath(self, m, n, i, j: int, grid: List[List[int]], visited) -> int:
          if [i,j] in visited or i<0 or j<0 or i>=m or j>=n or grid[i][j] == 0:
               return 0
          else:
               visited.append([i,j])
               left = self.searchForPath(m, n, i, j-1, grid, visited)
               right = self.searchForPath(m, n, i, j+1, grid, visited)
               up = self.searchForPath(m, n, i-1, j, grid, visited)
               down = self.searchForPath(m, n, i+1, j, grid, visited)
               visited.remove([i,j])
               return max((up, down, left, right)) + grid[i][j]
