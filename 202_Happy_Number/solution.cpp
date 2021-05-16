#include <unordered_set>
#include "header.h"

bool isHappy(int n)
{
    unordered_set<int> processed;

    while (true)
    {
        processed.insert(n);

        int sum = 0;
        while (n > 0)
        {
            int remain = n % 10;
            n /= 10;
            sum += remain * remain;
        }
        n = sum;

        if (n == 1)
        {
            return true;
        }
        else if (processed.find(n) != processed.end())
        {
            return false;
        }
    }
}