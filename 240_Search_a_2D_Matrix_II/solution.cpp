#include "header.h"

// Check elements in diagonal line, when matrix[row][col] > target,
// the target can only be in either the bottom-left or top-right area
// of the matrix divided by axes row and col(including row and col).

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    // Find an element in diagonal line that is larger than target
    int row = 0, col = 0;
    while (row < m && col < n && matrix[row][col] < target)
    {
        ++row;
        ++col;
    }

    // Binary search in bottom left area
    for (int i = row; i < m; i++)
    {
        int left = 0;
        int right = min(col, n - 1);
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (matrix[i][mid] == target)
            {
                return true;
            }
            else if (matrix[i][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    // binary search in top-right area
    for (int j = col; j < n; j++)
    {
        int up = 0;
        int down = min(row, m - 1);

        while (up <= down)
        {
            int mid = (up + down) / 2;
            if (matrix[mid][j] == target)
            {
                return true;
            }
            else if (matrix[mid][j] > target)
            {
                down = mid - 1;
            }
            else
            {
                up = mid + 1;
            }
        }
    }

    return false;
}