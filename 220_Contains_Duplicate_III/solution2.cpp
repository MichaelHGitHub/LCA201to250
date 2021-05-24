#include <set>
#include "header.h"

bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t)
{
    set<long long> keep;
    for (int i = 0; i < nums.size(); i++)
    {
        if (keep.size() > k)
        {
            keep.erase(nums[i - k - 1]);
        }

        // -t <= x-nums[i] <= t ==> x >= nums[i] -t; 
        // Retrieve x if exists, and verify (x - nums[i] <= t)
        set<long long>::iterator it = keep.lower_bound((long long)nums[i] - t);
        if (it != keep.end() && *it - nums[i] <= t)
        {
            return true;
        }

        //// Or do it in two steps: x - nums[i] <= t and nums[i] - x <= t;
        //// Retrieve the lest one that is larger or equal than nums[i] and 
        //// verify x - nums[i] <= t;
        //set<int>::iterator it = keep.lower_bound(nums[i]);
        //if (it != keep.end() && (long long)(*it) - nums[i] <= t)
        //{
        //    return true;
        //}

        //// The previous element(if exist) is the largest one that is less
        //// than nums[i], verify (nums[i] - x <= t).
        //if (it != keep.begin() &&
        //    (long long)nums[i] - *(--it) <= t)
        //{
        //    return true;
        //}

        keep.insert(nums[i]);
    }

    return false;
}