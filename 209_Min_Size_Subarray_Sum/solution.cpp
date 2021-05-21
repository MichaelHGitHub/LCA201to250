#include "header.h"

// Two pointer
int minSubArrayLen(int target, vector<int>& nums)
{
    int result = INT32_MAX;
    int sum = 0;
    int left = 0;
    int right = 0;
    int size = nums.size();

    // Start from left, calculate the sum, increase right by 1 at a time
    while (left < size && right < size && right >= left)
    {
        sum += nums[right];

        // If sum is good, deduct nums[left] to check if
        // sum is still good. and repeat until sum is not good.
        while (sum >= target)
        {
            result = min(result, right - left + 1);
            sum -= nums[left];
            ++left;
        }
        ++right;
    }

    return (result == INT32_MAX ? 0 : result);
}