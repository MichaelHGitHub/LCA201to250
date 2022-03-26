#include "header.h"

vector<int> majorityElement_r(vector<int>& nums)
{
    vector<int> result;

    int top1 = INT32_MIN, top2 = INT32_MIN;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == top1)
        {
            ++count1;
        }
        else if(nums[i] == top2)
        {
            ++count2;
        }
        else
        {
            if (top1 == INT32_MIN)
            {
                top1 = nums[i];
                count1 = 1;
                continue;
            }

            if (top2 == INT32_MIN)
            {
                top2 = nums[i];
                count2 = 1;
                continue;
            }

            --count1;
            --count2;

            if (count1 == 0)
            {
                top1 = INT32_MIN;
            }

            if (count2 == 0)
            {
                top2 = INT32_MIN;
            }
        }
    }

    // Count occurrence of top1 and top2
    count1 = 0, count2 = 0;
    for(int number: nums)
    {
        if (number == top1)
        {
            ++count1;
        }

        if (number == top2)
        {
            ++count2;
        }
    }

    if (count1 > nums.size() / 3)
    {
        result.push_back(top1);
    }

    if (count2 > nums.size() / 3)
    {
        result.push_back(top2);
    }

    return result;
}