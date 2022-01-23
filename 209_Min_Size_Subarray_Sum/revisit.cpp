#include "header.h"

int minSubArrayLen_r(int target, vector<int>& nums)
{
    int result = INT32_MAX;
    int pos1 = 0;
    int pos2 = 0;
    int sum = 0;

    while (pos1 <= pos2 && pos2 < nums.size())
    {
        sum += nums[pos2];

        while (sum >= target)
        {
            result = min(result, pos2 - pos1 + 1);
            sum -= nums[pos1];
            ++pos1;
        }
        ++pos2;
    }

    return result == INT32_MAX ? 0 : result;
}