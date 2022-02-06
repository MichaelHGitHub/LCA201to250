#include "header.h"

static int partion(vector<int>& nums, int left, int right);
static void QuickSort(vector<int>& nums, int left, int right, int k);

int findKthLargest_r(vector<int>& nums, int k)
{
    QuickSort(nums, 0, nums.size() - 1, k);
    return nums[nums.size() - k];
}

void QuickSort(vector<int>& nums, int left, int right, int k)
{
    if (left < right)
    {
        int pvoit = partion(nums, left, right);

        if (nums.size() - k != pvoit)
        {
            QuickSort(nums, left, pvoit - 1, k);
            QuickSort(nums, pvoit + 1, right, k);
        }
    }
}

int partion(vector<int>& nums, int left, int right)
{
    int pvoit = right;
    --right;

    while (left <= right)
    {
        while (left <= right && nums[right] >= nums[pvoit])
        {
            --right;
        }

        if (left <= right && nums[left] <= nums[pvoit])
        {
            left++;
        }

        if (left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }

    if (left != pvoit)
    {
        int temp = nums[left];
        nums[left] = nums[pvoit];
        nums[pvoit] = temp;
    }

    return left;
}