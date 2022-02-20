#include "header.h"
#include <unordered_map>

bool containsNearbyAlmostDuplicate_r(vector<int>& nums, int k, int t)
{
    bool result = false;

    std::unordered_map<int, int> visited;

    int left = 0;
    int right = 1;

    while (right < nums.size())
    {
        if (right - left > k)
        {
            ++left;
        }

        if (visited.find(nums[right]) != visited.end() &&
            right - visited[nums[right]] <= k)
        {
            left = visited[nums[right]];
        }

        for (int i = left; i < right; i++)
        {
            if (abs((long)nums[i] - (long)nums[right]) <= (long)t)
            {
                result = true;
                break;
            }
        }

        visited[nums[right]] = right;
        ++right;
    }

    return result;
}