#include "sort.h"

int partition(vector<int>& nums, int start, int end);
void quickSort(vector<int>& nums, int start, int end);

void quickSort(vector<int>& nums)
{
    if (0 == nums.size())
    {
        return;
    }

    quickSort(nums, 0, nums.size() - 1);
}

void quickSort(vector<int>& nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    // nums[end] will be the pivot value
    int pivot = partition(nums, start, end);

    quickSort(nums, start, pivot - 1);
    quickSort(nums, pivot + 1, end);

}

int partition(vector<int>& nums, int start, int end)
{
    if (start >= end)
    {
        return start;
    }

    // Choose nums[end] as pivot value
    int pivot = nums[end];
    int pivoi_index = end;
    int left = start;
    int right = end - 1;

    while (left < right)
    {
        while (left < right && nums[left] <= nums[end])
        {
            left++;
        }

        while (left < right && nums[right] >= nums[end])
        {
            right--;
        }

        if (left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }

    // put pivot in position only if nums[left] still larger than nums[end]
    if (left != end && nums[left] > nums[end])
    {
        int temp = nums[left];
        nums[left] = nums[end];
        nums[end] = temp;

        // remember the pivot index
        pivoi_index = left;
    }

    return pivoi_index;
}