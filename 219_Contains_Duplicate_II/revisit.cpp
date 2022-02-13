#include "header.h"
#include <unordered_map>

bool containsNearbyDuplicate_r(vector<int>& nums, int k)
{
    bool result = false;
    std::unordered_map<int, int> visited;

    for (int i = 0; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end())
        {
            if (abs(visited[nums[i]] - i) <= k)
            {
                result = true;
                break;
            }
        }
        visited[nums[i]] = i;
    }
    return result;
}