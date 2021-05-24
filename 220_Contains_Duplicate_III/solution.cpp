#include "header.h"

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    if (nums.size() < 2)
    {
        return false;
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j <= k + i && j < nums.size(); j++)
        {
            long long li = nums[i];
            long long lj = nums[j];
            if (abs(li - lj) <= t &&
                j - i <= k)
            {
                return true;
            }
        }
    }

    return false;
}