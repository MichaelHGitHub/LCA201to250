#include "header.h"

// DP:
// Have another 2-D array to save the max length of each element in matrix,
// length[i][j] = 1 + smallest(length[i-1][j-1] , length[i-1][j], length[i][j-1]),
// Draw a picture, it will help understand why. 

int maximalSquare(vector<vector<char>>& matrix)
{
    vector<vector<int>> marks(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

    int max_length = 0;
    for (int i = 1; i < marks.size(); i++)
    {
        for (int j = 1; j < marks[i].size(); j++)
        {
            if (matrix[i - 1][j - 1] == '1')
            {
                marks[i][j] = min(marks[i-1][j-1], min(marks[i - 1][j], marks[i][j - 1])) + 1;
                max_length = max(max_length, marks[i][j]);
            }
        }
    }

    return max_length * max_length;
}