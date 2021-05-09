class Solution {
public:

  int searchForPath(const size_t m, const size_t n, const size_t i, const size_t j, const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited)
  {
    if ( (i < 0) || (j < 0) || (i >= m) || (j >= n) || (visited[i][j]) || (grid[i][j] == 0) ) return 0;
    
    else
      {
	visited[i][j] = true;
	int left = searchForPath(m, n, i, j - 1, grid, visited);
	int right = searchForPath(m, n, i, j + 1, grid, visited);
	int up = searchForPath(m, n, i - 1, j, grid, visited);
	int down = searchForPath(m, n, i + 1, j, grid, visited);
	visited[i][j] = false;

	return (std::max(up, std::max(down, std::max(left, right))) + grid[i][j]);
      }
  }
  
    int getMaximumGold(const std::vector<std::vector<int>>& grid) {
      
      const size_t m{grid.size()};
      const size_t n{grid[0].size()};
      std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
      int total_gold{0};

      for (size_t i{0}; i < m; ++i)
	{
	  for (size_t j{0}; j < n; ++j)
	    {
	      if (grid[i][j] != 0)
		{
		  int path_from_cell = searchForPath(m, n, i, j, grid, visited);
		  total_gold = std::max(total_gold, path_from_cell);
		}
	    }
	}

      return total_gold;
    }
};
