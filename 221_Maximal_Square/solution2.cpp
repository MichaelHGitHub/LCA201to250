#include "header.h"

static int getSquareLength(vector<vector<char>>& matrix, int row, int col);

// Brute force:
// Check the square starting from every '1', find the max length.

int maximalSquare2(vector<vector<char>>& matrix)
{
    int max_length = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                max_length = max(max_length, getSquareLength(matrix, i, j));
            }
        }
    }

    return max_length * max_length;
}

int getSquareLength(vector<vector<char>>& matrix, int row, int col)
{
    int i = row;
    int j = col;

    // Each time, we only need to check the bottom and right edges, 
    // the rest of the elements are checked in the previous iteration.
    while (i < matrix.size() && j < matrix[i].size())
    {
        // Check the bottom edge.
        int k = col;
        while( k <= j)
        {
            if (matrix[i][k] == '0')
            {
                break;
            }

            ++k;
        }

        if (k <= j)
        {
            break;
        }

        // Check the right edge.
        k = row;
        while (k <= i)
        {
            if (matrix[k][j] == '0')
            {
                break;
            }
            ++k;
        }

        if (k <= i)
        {
            break;
        }

        ++i;
        ++j;
    }

    return i - row;
}