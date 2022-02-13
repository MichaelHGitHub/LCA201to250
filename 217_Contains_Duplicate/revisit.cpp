#include "header.h"
#include <unordered_set>

bool containsDuplicate_r(vector<int>& nums)
{
    bool result = false;
    std::unordered_set<int> visited;

    for (int i = 0; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end())
        {
            result = true;
            break;
        }

        visited.insert(nums[i]);
    }

    return result;
}