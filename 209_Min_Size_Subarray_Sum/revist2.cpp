#include "header.h"

int minSubArrayLen_r2(int target, vector<int>& nums)
{
    int result = INT32_MAX;

    vector<int> sums(nums.size() + 1, 0);

    for (int i = 1; i < sums.size(); i++)
    {
        sums[i] = sums[i - 1] + nums[i - 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int pos1 = i;
        int pos2 = nums.size() - 1;

        while (pos1 <= pos2)
        {
            int mid = (pos1 + pos2) / 2;
            if (sums[mid + 1] - sums[i] >= target)
            {
                result = min(result, mid - i + 1);
                pos2 = mid - 1;
            }
            else
            {
                pos1 = mid + 1;
            }
        }
    }
    return result == INT32_MAX ? 0 : result;
}