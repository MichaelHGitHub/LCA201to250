#include "header.h"

static void helper(vector<vector<int>>& result, vector<int>& one_set, int k, int n, int numbers, int sum, int val);


vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> result;
    vector<int> one_set(k, 0);
    helper(result, one_set, k, n, 0, 0, 0);

    return result;
}

static void helper(vector<vector<int>>& result,  vector<int>& one_set, int k, int n, int numbers, int sum, int val)
{
    if (numbers == k)
    {
        if (sum == n)
        {
            result.push_back(one_set);
        }
        return;
    }

    for (int i = val + 1; i < 10; i++)
    {
        one_set[numbers] = i;
        helper(result, one_set, k, n, numbers + 1, sum + i, i);
        one_set[numbers] = 0;
    }
}