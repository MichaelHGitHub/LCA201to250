#include "header.h"

static int partition(vector<int>& nums, int left, int right);
static void swap(vector<int>& nums, int i, int j);

// We could sort the entire array and find the element nums[size-k].
// However, what we really care about is the one that would be in the
// postion (size-k), other elements doesn't matter.
// Doesn't this sound like the partition of quick sort? which places
// one pivot to its postion at a time.
// So, let's do quick sort, as soon as we place the pivot(size -k) to its 
// postion, no need to proceed with the rest of the quick sort.

int findKthLargest(vector<int>& nums, int k)
{
    int left = 0;
    int right = nums.size() - 1;
    k = nums.size() - k;

    while (right > left)
    {
        int pos = partition(nums, left, right);

        if (pos < k)
        {
            left = pos + 1;
        }
        else if(pos > k)
        {
            right = pos - 1;
        }
        else
        {
            // bingo, this is the one we need.
            break;
        }
    }
    return nums[k];
}

int partition(vector<int>& nums, int left, int right)
{
    // Use the most right one as pivot.
    int pivot = right;
    --right;

    while (right >= left)
    {
        while (right >= left && nums[left] <= nums[pivot])
        {
            ++left;
        }

        while (right >= left && nums[right] >= nums[pivot])
        {
            --right;
        }

        if (right > left)
        {
            swap(nums, left, right);
        }
    }
    // place pivoit to its postion
    swap(nums, left, pivot);

    return left;
}

void swap(vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}