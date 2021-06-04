#include "header.h"

// Two passes
// First pass:
// res[i] = nums[0]*...*nums[i-1].
// Second pass:
// res[i] = res[i] * (nums[i+1]*...*nums[n-1]);

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> result(nums.size(), 1);

    // Left = nums[0]*...*nums[i-1]
    int left = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        result[i] = left;
        left *= nums[i];
    }

    // right = nums[n-1]*nums[n-2]...nums[i+1]
    int right = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        result[i] *= right;
        right *= nums[i];
    }

    return result;
}