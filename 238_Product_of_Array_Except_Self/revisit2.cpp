#include "header.h"

vector<int> productExceptSelf_r2(vector<int>& nums)
{
    vector<int> results(nums.size(), 1);

    int left = nums[0];
    for (int i = 1; i < results.size(); i++)
    {
        results[i] = left;
        left *= nums[i];
    }

    int right = nums[nums.size() - 1];
    for (int i = results.size() - 2; i >= 0; i--)
    {
        results[i] = results[i] * right;
        right *= nums[i];
    }

    return results;
}