#include "header.h"

// Binary Search

int minSubArrayLen2(int target, vector<int>& nums)
{
    int result = INT32_MAX;
    int size = nums.size();
    vector<int> sums(size, 0);

    // Calculate all the sums so that we don't have to do it duplicately in the 
    // loop. 
    sums[0] = nums[0];
    for (int i = 1; i < size; i++)
    {
        sums[i] = sums[i - 1] + nums[i];
    }

    // Start from each of the element, calculate sum
    for (int i = 0; i < size; i++)
    {
        int left = i;
        int right = size - 1;

        // Use binary search to determine the end element for the sum
        while (right >= left)
        {
            int mid = (right + left) / 2;
            if (sums[mid] - sums[i] + nums[i] >= target)
            {
                result = min(result, mid - i + 1);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    return result == INT32_MAX ? 0 : result;
}