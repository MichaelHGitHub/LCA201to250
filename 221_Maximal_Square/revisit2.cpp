#include "header.h"

static int squareLength(vector<vector<int>>& records, vector<vector<char>>& matrix, int row, int col);

int maximalSquare_r2(vector<vector<char>>& matrix)
{
    int len = 0;
    vector<vector<int>> records(matrix.size(), vector<int>(matrix[0].size(), -1));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            len = max(len, squareLength(records, matrix, i, j));
        }
    }

    return len*len;
}

int squareLength(vector<vector<int>>& records, vector<vector<char>>& matrix, int row, int col)
{
    if (row == matrix.size() || col == matrix[row].size())
    {
        return 0;
    }

    if (records[row][col] != -1)
    {
        return records[row][col];
    }

    int nextSquareLen = squareLength(records, matrix, row + 1, col + 1);

    int squareLen = 0;

    int r = row, c = col;

    while (r <= row + nextSquareLen && matrix[r][col] == '1' &&
        c <= col + nextSquareLen && matrix[row][c] == '1')
    {
        ++squareLen;
        ++r;
        ++c;
    }

    records[row][col] = squareLen;
    return squareLen;
}