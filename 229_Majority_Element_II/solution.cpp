#include "header.h"

// There can't be more than 2 numbers that appears in the array
// more than n/3 ocurrance. So we can find the top 2 most frequent 
// numbers in the array, and check if their ocurrence more than n/3.
// Use Boyer-Moore Majority Vote to find out the top 2 numbers
// Remember what we do to find top 1 that appears more than n/2? the
// exact same idea here.

vector<int> majorityElement(vector<int>& nums) {

    vector<int> result;

    int m1 = INT32_MAX, m2 = INT32_MAX;
    int c1 = 0, c2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // Add vote 
        if (m1 == nums[i])
        {
            ++c1;
            continue;
        }

        if (m2 == nums[i])
        {
            ++c2;
            continue;
        }

        if (c1 == 0)
        {
            m1 = nums[i];
            c1 = 1;
            continue;
        }

        if (c2 == 0)
        {
            m2 = nums[i];
            c2 = 1;
            continue;
        }

        // Deduct vote
        --c1;
        --c2;
        // Reset the count to 0 so that it can receive a new value
        if (c1 < 0)
        {
            c1 = 0;
            m1 = INT32_MAX;
        }

        if (c2 < 0)
        {
            c2 = 0;
            m2 = INT32_MAX;
        }
    }

    // Check the ocurrence of top 2 numbers.
    c1 = 0;
    c2 = 0;
    for (int num : nums)
    {
        if (num == m1)
        {
            ++c1;
        }

        if (num == m2)
        {
            ++c2;
        }
    }

    if (c1 > nums.size() / 3)
    {
        result.push_back(m1);
    }
    if (c2 > nums.size() / 3)
    {
        result.push_back(m2);
    }

    return result;
}