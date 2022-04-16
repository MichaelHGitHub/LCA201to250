#include "header.h"

bool searchMatrix_r2(vector<vector<int>>& matrix, int target)
{
    bool result = false;
    int i = 0;
    int j = matrix[i].size() - 1;

    while (i < matrix.size() && j < matrix[i].size())
    {
        if (matrix[i][j] == target)
        {
            result = true;
            break;
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

    return result;
}