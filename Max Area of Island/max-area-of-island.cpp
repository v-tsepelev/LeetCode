class Solution {
public:
  
  int area(const size_t i, const size_t j, std::vector<std::vector<int>>& grid)
  {
    if ((i < 0) || (i >= grid.size()) || (j < 0) || (j >= grid[0].size()) || (grid[i][j] == 0) || (grid[i][j] == 2))
      {
	return 0;
      }
    else
      {
	grid[i][j] = 2;
	return (1 + area(i, j - 1, grid) + area(i, j + 1, grid) + area(i - 1, j, grid) + area(i + 1, j, grid));
      }
  }
  
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
  {
    int answer{0};
    size_t m{grid.size()};
    size_t n{grid[0].size()};
    for (int i = 0; i < m; ++i)
      {
	for (int j = 0; j < n; ++j)
	  {
	    answer = std::max(answer, area(i, j, grid));
	  }
      }
    return answer;
  }
};
