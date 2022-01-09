#include "header.h"

int countPrimes_r(int n)
{
    int count = 0;
    vector<bool> visited(n, true);

    for (int i = 2; i * i < n; i++)
    {
        if (!visited[i])
        {
            continue;
        }

        for (int j = i, product = 0; (product = i * j) < n; j++)
        {
            visited[product] = false;
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (visited[i])
        {
            ++count;
        }
    }

    return count;
}

