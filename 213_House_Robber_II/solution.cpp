#include "header.h"

static int helper(vector<int>& nums, vector<int>& max_gain, int start, int end);

// Recursive:
// Need to calculate gain(0->n-2), gain(1->n-1), gain(2->n-1). 
// Each time, also need to try skip 1, 2 houses. 
// Save max gain of up-to-eac-house to reduce recurrsion.
int rob(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> max_gain(nums.size(), -1);
    int solution1 = helper(nums, max_gain, 0, nums.size() - 2);

    // Can carry the data from previous try.
    max_gain.assign(nums.size(), -1);
    int solution2 = helper(nums, max_gain, 1, nums.size() - 1);

    max_gain.assign(nums.size(), -1);
    int solution3 = helper(nums, max_gain, 2, nums.size() - 1);

    return max(solution1, max(solution2, solution3));
}

int helper(vector<int>& nums, vector<int>& max_gain, int start, int end)
{
    if (start > end)
    {
        return 0;
    }

    if (max_gain[start] != -1)
    {
        return max_gain[start];
    }

    int solution1 = nums[start] + helper(nums, max_gain, start + 2, end);
    int solution2 = nums[start] + helper(nums, max_gain, start + 3, end);

    max_gain[start] = max(solution1, solution2);

    return max_gain[start];
}