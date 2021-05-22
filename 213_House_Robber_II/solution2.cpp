#include "header.h"

// DP
// Calculate gain(0->n-2) and gain(1->n-1). 

int rob2(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    if (nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }

    // Add 3 more space because we need to skip 1 house. otherwise it could
    // be 2.
    vector<int> record(nums.size() + 3, 0);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        record[i + 3] = nums[i] + max(record[i + 1], record[i]);
    }
    int solution1 = max(record[record.size() - 2], record[record.size() - 3]);

    record.assign(nums.size() + 3, 0);
    for (int i = 1; i < nums.size(); i++)
    {
        record[i + 3] = nums[i] + max(record[i + 1], record[i]);
    }
    int solution2 = max(record[record.size() - 1], record[record.size() - 2]);

    return max(solution1, solution2);
}

