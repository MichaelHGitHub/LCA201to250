#include <unordered_map>
#include "header.h"

bool containsNearbyDuplicate(vector<int>& nums, int k) {

    unordered_map<int, int> visited;

    for (int i = 0; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end() &&
            i - visited[nums[i]] <= k)
        {
            return true;
        }

        visited[nums[i]] = i;
    }

    return false;
}