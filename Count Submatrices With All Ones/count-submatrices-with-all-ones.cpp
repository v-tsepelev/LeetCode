class Solution {
public:

  int width(int i, int j, std::vector<std::vector<int>>& mat)
  {
    int output{1};
    while ((j+1 < mat[0].size()) && (mat[i][j+1] == 1))
      {
	output += 1;
	j += 1;
      }
    return output;
  }

  int localNumSubmat(int i, int j, std::vector<std::vector<int>>& mat)
  {
    int maxWidth{width(i, j, mat)};
    int N{width(i, j, mat)};

    while ((i+1 < mat.size()) && (mat[i+1][j] == 1))
      {
	maxWidth = std::min(maxWidth, width(i+1, j, mat));
	N += maxWidth;
	i += 1;
      }

    return N;
  }
  
    int numSubmat(std::vector<std::vector<int>>& mat)
  {
    int number{};

    for (int i = 0; i < mat.size(); ++i)
      {
	for (int j = 0; j < mat[0].size(); ++j)
	  {
	    if (mat[i][j] == 1)
	      {
		number += localNumSubmat(i, j, mat);
	      }
	  }
      }

    return number;
  }
};
