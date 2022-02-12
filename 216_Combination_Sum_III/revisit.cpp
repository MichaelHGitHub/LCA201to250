#include "header.h"

static void combination(vector<vector<int>>& result, vector<int> oneSet, int curNum, int curSum, int curVal, int k, int n);

vector<vector<int>> combinationSum3_r(int k, int n)
{
    vector<vector<int>> result;
    vector<int> oneSet(k, 0);
    combination(result, oneSet, 0, 0, 0, k, n);

    return result;
}

void combination(vector<vector<int>>& result, vector<int> oneSet, int curNum, int curSum, int curVal, int k, int n)
{
    if (curNum == k)
    {
        if (curSum == n)
        {
            result.push_back(oneSet);
        }
        return;
    }

    for (int i = curVal + 1; i < 10; i++)
    {
        oneSet[curNum] = i;
        combination(result, oneSet, curNum + 1, curSum + i, i, k, n);
        oneSet[curNum] = 0;
    }
}