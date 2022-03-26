#include "header.h"

vector<string> summaryRanges_r(vector<int>& nums)
{
    vector<string> result;

    if (nums.size() > 0)
    {
        int start = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1] + 1)
            {
                if (i - 1 == start)
                {
                    result.push_back(std::to_string(nums[start]));
                }
                else
                {
                    result.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[i - 1]));
                }

                start = i;
            }
        }

        // Add very last range
        if (nums.size() - 1 == start)
        {
            result.push_back(std::to_string(nums[start]));
        }
        else
        {
            result.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[nums.size() - 1]));
        }
    }
    return result;
}