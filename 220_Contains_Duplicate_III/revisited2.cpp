#include "header.h"
#include <set>

bool containsNearbyAlmostDuplicate_r2(vector<int>& nums, int k, int t)
{
    bool result = false;

    int left = 0;
    int right = 0;
    std::set<long> keep;

    while (right < nums.size())
    {
        if (right - left > k)
        {
            keep.erase(nums[left]);
            ++left;
        }

        std::set<long>::iterator it = keep.lower_bound(nums[right]);

        if (it != keep.end() && *it - nums[right] <= t)
        {
            result = true;
            break;
        }

        if (keep.size() > 0 && it != keep.begin() && (long)nums[right] - *(--it) <= t)
        {
            result = true;
            break;
        }

        keep.insert(nums[right]);
        ++right;
    }
    return result;
}