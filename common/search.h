#pragma once

#include <vector>

using namespace std;

/// <summary>
/// Find a given number in a given rang in an array sorted in ascent order
/// </summary>
/// <param name="nums">The given array</param>
/// <param name="target">The number to be found</param>
/// <param name="left">The starting index(included) of the rang</param>
/// <param name="right">The ending index(included) of the rang</param>
/// <returns>The index of target or -1 if target doesn't exist in the range</returns>
int binarySearch(vector<int>& nums, int target, int left, int right);

/// <summary>
/// Find a given number in an array sorted in ascent order
/// </summary>
/// <param name="nums">The given array</param>
/// <param name="target">The number to be found</param>
/// <returns>The index of target or -1 if target doesn't exist in the array</returns>
int binarySearch(vector<int>& nums, int target);
