#include "header.h"

vector<int> productExceptSelf_r(vector<int>& nums)
{
    vector<int> results(nums.size(), 1);
    vector<int> temp(nums.size(), 1);

    // Calculate res[i] = nums[0]*...nums[i-1]
    for (int i = 1; i < nums.size(); i++)
    {
        results[i] = results[i - 1] * nums[i - 1];
    }

    // Calculate res[i] = nums[i+1]*...nums[n];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        temp[i] = temp[i + 1] * nums[i + 1];
    }

    // multiply two phases to get the results
    for (int i = 0; i < nums.size(); i++)
    {
        results[i] = results[i] * temp[i];
    }

    return results;
}