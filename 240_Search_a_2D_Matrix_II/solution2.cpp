#include "header.h"

// Start from top-right element, the rest of the moves are simple.

bool searchMatrix2(vector<vector<int>>& matrix, int target)
{
    int i = 0;
    int j = matrix[0].size() - 1;

    while (i < matrix.size() && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
        {
            --j;
        }
        else
        {
            ++i;
        }
    }

    return false;
}