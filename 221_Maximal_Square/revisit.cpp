#include "header.h"

static int areaOfSquare(vector<vector<char>>& matrix, int x, int y);

int maximalSquare_r(vector<vector<char>>& matrix)
{
    int area = 0;

    for (int i =0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                area = max(area, areaOfSquare(matrix, i, j));
            }
        }
    }

    return area;
}

int areaOfSquare(vector<vector<char>>& matrix, int row, int col)
{
    int r = row, c = col;

    while (r < matrix.size() && matrix[r][col] == '1' &&
           c < matrix[row].size() && matrix[row][c] == '1')
    {
        bool isSquare = true;
        for (int i = row + 1; i <= r; i++)
        {
            if (matrix[i][c] != '1')
            {
                isSquare = false;
                break;
            }
        }

        if (isSquare)
        {
            for (int j = col + 1; j <= c; j++)
            {
                if (matrix[r][j] != '1')
                {
                    isSquare = false;
                    break;
                }
            }
        }

        if (!isSquare)
        {
            break;
        }

        ++r;
        ++c;
    }
    return (r - row) * (r - row);
}