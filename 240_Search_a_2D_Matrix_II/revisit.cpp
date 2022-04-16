#include "header.h"

static bool BinarySearch(vector<vector<int>>& matrix, int row, int col, int target);

bool searchMatrix_r(vector<vector<int>>& matrix, int target)
{
    bool result = false;
    int i = 0, j = 0;

    while(i < matrix.size() && j < matrix[i].size())
    {
        if (matrix[i][j] == target)
        {
            result = true;
            break;
        }
        else if (matrix[i][j] > target)
        {
            if (BinarySearch(matrix, i, j, target))
            {
                result = true;
                break;
            }
        }

        ++i;
        ++j;

        if (i == matrix.size() && j < matrix[i - 1].size())
        {
            --i;
        }

        if (i < matrix.size() && j == matrix[i].size())
        {
            --j;
        }
    }

    return result;
}


bool BinarySearch(vector<vector<int>>& matrix, int row, int col, int target)
{
    int begin = 0;
    int end = col;

    while (begin <= end)
    {
        int mid = (begin + end) / 2;

        if (matrix[row][mid] == target)
        {
            return true;
        }
        else if (matrix[row][mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    begin = 0;
    end = row;

    while (begin <= end)
    {
        int mid = (begin + end) / 2;

        if (matrix[mid][col] == target)
        {
            return true;
        }
        else if (matrix[mid][col] > target)
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    return false;
}