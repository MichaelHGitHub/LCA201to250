#include "header.h"

int rob_r(vector<int>& nums)
{
    int result = 0;

    if (nums.size() == 1)
    {
        result = nums[0];
    }
    else
    {
        vector<int> dp0(nums.size() + 2, 0);
        vector<int> dp1(nums.size() + 2, 0);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            dp0[i + 3] = max(dp0[i], dp0[i + 1]) + nums[i];
        }

        for (int i = 1; i < nums.size(); i++)
        {
            dp1[i + 2] = max(dp1[i - 1], dp1[i]) + nums[i];
        }

        result = max(max(dp0[dp0.size() - 1], dp0[dp0.size() -2]),
                     max(dp1[dp1.size() -1], dp1[dp1.size() - 2]));
    }

    return result;
}