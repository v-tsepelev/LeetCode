from typing import List

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:

        def localNumSubmat(i, j: int, mat: List[List[int]]) -> int:

            def width(i, j: int, mat: List[List[int]]) -> int:
                output = 1
                while (j+1) < len(mat[0]) and mat[i][j+1] == 1:
                    output += 1
                    j += 1
                return output

            maxWidth = width(i, j, mat)
            N = width(i, j, mat)
            
            while (i+1) < len(mat) and mat[i+1][j] == 1:
                maxWidth = min(maxWidth, width(i+1, j, mat))
                N += maxWidth
                i += 1

            return N

        number = 0
        
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    number += localNumSubmat(i, j, mat)

        return number
