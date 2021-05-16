#include "search.h"

int binarySearch(vector<int>& nums, int target)
{
    return binarySearch(nums, target, 0, nums.size() - 1);
}

int binarySearch(vector<int>& nums, int target, int left, int right)
{
    if (0 == nums.size() || left > right)
    {
        return -1;
    }

    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (target == nums[mid])
        {
            result = mid;
            break;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}
